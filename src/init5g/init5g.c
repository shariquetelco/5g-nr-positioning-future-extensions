#include "init5g.h"

int fd[2] = {-1};

#ifdef CORE

/*Global variables*/
bool isPos = false;
pid_t amfd = -1, lmfd = -1;
int gnb = 0;

/*
 * resetInit - clean up everything after a positioning measurement iteration
 *
 * @signum: signal that triggers the execution of this signal handler (here: SIGTERM)
 */
static void
resetInit(int signum)
{
	if(signum != SIGTERM)
	{
		return;
	}

	/*Reset global gNB counter*/
	gnb = 0;

	return;
}

/*
 * finishUERegistration - signal handler which is invoked when the AMF has a new UE registered (NG Setup procedure).
 *
 * @signum: signal number
 */
static void
finishUERegistration(int signum)
{
	if(signum != SIGUSR1)
	{
		return;
	}

	/*Increase gNB counter*/
	gnb++;

	return;
}

/*
 * finishUERegistration - signal handler which is invoked when the AMF has positioning completed.
 *
 * @signum: signal number
 */
static void
finishPositioning(int signum)
{
	if(signum != SIGUSR2)
	{
		return;
	}

	isPos = true;

	return;
}
#endif

/*
 * initProcess - fork init5g process and execute a new program
 *
 * @argvp: argument vector of new program
 * @envp: enviroment variables that are passed to the new program
 *
 * return: PID of newly created process
 */
static pid_t
initProcess(char **argvp, char **envp, bool waiting)
{
	/*Variables*/
	pid_t pid;
	int ret;

	/*Testing: starting sh(1)*/
	if(argvp[0] == 0)
	{
		dprintf(fd[0], "[init5g] initProcess: Invalid argv pointer\n");
		return -1;
	}
	else if((pid = fork()) < 0)
	{
		dprintf(fd[0], "[init5g] fork: %s\n", strerror(errno));
		return -1;
	}

	/*Child: Starting shell*/
	if(pid == 0)
	{
		if(execve(argvp[0], argvp, envp) < 0)
		{
			dprintf(fd[0], "[init5g] Couldn't start program %s: %s\n", argvp[0], strerror(errno));
			exit(EXIT_FAILURE);
		}
	}

	/*Parent: Waiting for termination of its child*/
	else if(waiting)
	{
		if(wait(&ret) < 0)
		{
			printf("[init5g] initProcess: %s\n", strerror(errno));
			return -1;
		}

		if(WIFEXITED(ret))
		{
			dprintf(fd[0], "[init5g] Child process %d (%s) terminated with exit code %d\n", pid, argvp[0], WEXITSTATUS(ret));
		}
		else if(WIFSIGNALED(ret))
		{
			dprintf(fd[0], "[init5g] Child process %d (%s) terminated by signal %d\n", pid, argvp[0], WTERMSIG(ret));
		}
		else
		{
			dprintf(fd[0], "[init5g] Child process %d (%s): Unknown return from wait(2)\n", pid, argvp[0]);
		}
	}
	else
	{
		return pid;
	}

	return -1;
}

/*
 * main - entry point of the program
 *
 * return: EXIT_SUCCESS on success, EXIT_FAILURE otherwise
 */
int
main(int argc, char **argv)
{
	/*Variables*/
	char *envp[ENV_SIZE] = {0};
	char *argvp[ARGV_SIZE] = {0};
#ifdef CORE
	struct sigaction act = {0};
	int k = 0;
	int iter_max = 0;
#ifdef REPORT
        char period[16] = {0};
#endif
#endif
	int i, j, ret = 0;
	char buf[BUF_MAX] = {0};
	char npool[16] = {0};

#ifdef REPORT
	int l = 0;
#endif

#ifdef CORE
	printf("\n==== init5g v%s-core ====\n", INIT_VER);
#else
	printf("\n==== init5g v%s-gnb ====\n", INIT_VER);
#endif

	/*(0) Initialize enironment variable list*/
	envp[0] = ENV_PATH;
	envp[1] = ENV_PWD;
	envp[2] = ENV_LDPATH;
	envp[3] = NULL;

	/*
	 * (1) Execute interpreter script to do:
	 *
	 * - mount of pseudo filesystems sysfs and proc
	 * - initialize network interfaces
	 * - load required kernel modules
	 */
	argvp[0] = BIN_INIT;
	argvp[1] = NULL;
	fd[0] = STDOUT_FILENO;
	initProcess(argvp, envp, true);

#ifdef DEBUG
	argvp[0] = BIN_SH;
	argvp[1] = NULL;
	initProcess(argvp, envp, true);

	/*(2) Opening log file*/
	if((fd[0] = open(INIT_LOG, O_CREAT | O_EXCL | O_WRONLY, 0666)) < 0)
	{
		if(errno != EEXIST)
		{
			printf("[init5g] Target log file %s couldn't be opened: %s\n", INIT_LOG, strerror(errno));
			fflush(NULL);
			goto end;
		}

		else if((fd[0] = open(INIT_LOG, O_WRONLY | O_APPEND)) < 0)
		{
			printf("[init5g] Target log file %s couldn't be opened: %s\n", INIT_LOG, strerror(errno));
			fflush(NULL);
			goto end;
		}
	}
#endif
	/*Write header to file*/
#ifdef CORE
	dprintf(fd[0], "\n--- init5g-core v%s ---\n", INIT_VER);
#else
	dprintf(fd[0], "\n--- init5g-gnb v%s ---\n", INIT_VER);
#endif

#ifdef CORE
	/*
	 * (3a) Set signal handlers to handle (AMF) signaling
	 *
	 * SIGUSR1: Sent by AMF when at least one UE was successfully registered
	 * SIGUSR2: Sent by AMF when positioning of n UEs was completed.
	 * SIGTERM: Reset global gNB counter
	 */
	act.sa_handler = finishUERegistration;
	//act.sa_flags = SA_RESTART;
	if(sigemptyset(&act.sa_mask) != 0 || sigaction(SIGUSR1, &act, NULL) != 0)
	{
		dprintf(fd[0], "[init5g] Signal handler for SIGUSR1 couldn't be initialized: %s\n", strerror(errno));
		goto end;
	}

	act.sa_handler = finishPositioning;
	if(sigemptyset(&act.sa_mask) != 0 || sigaction(SIGUSR2, &act, NULL) != 0)
	{
		dprintf(fd[0], "[init5g] Signal handler for SIGUSR2 couldn't be initialized: %s\n", strerror(errno));
		goto end;
	}

	act.sa_handler = resetInit;
	if(sigemptyset(&act.sa_mask) != 0 || sigaction(SIGTERM, &act, NULL) != 0)
	{
		dprintf(fd[0], "[init5g] Signal handler for SIGTERM couldn't be initialized: %s\n", strerror(errno));
		goto end;
	}

#else
	/*
	 * (3b) Set hostname of this base station (gNB)
	 *
	 * Here: imd-gnbXXX, where XXX is a random number between 0 and 99.
	 */
	srand((unsigned int)time(NULL));
	snprintf(buf, BUF_MAX, "imd-gnb%d", rand()%100);

	if(sethostname(buf, strlen(buf)) != 0)
	{
		dprintf(fd[0], "[init5g] Hostname couldn't be set to %s: %s\n", buf, strerror(errno));
		goto end;
	}
#endif
#ifdef DEBUG
	/*
	 * (4) Closing stdout and stderr and use them for logging
	 */
	if((fd[0] = dup2(fd[0], STDOUT_FILENO)) < 0 || (fd[1] = dup2(fd[0], STDERR_FILENO)) < 0)
	{
		dprintf(fd[0], "[init5g] dup2: %s\n", strerror(errno));
		goto end;
	}
#endif
	/*
	 * (5) Starting selected 5G program(s)
	 *
	 * CORE: AMF, LMF (see BIN_AMF, BIN_LMF in init5g.h)
	 * otherwise: gNB (see BIN_GNB in init5g.h)
	 */
#ifdef CORE
	/*Loop 1: For each UE ...*/
	for(i = 2; i <= INIT_UE; i *= 2)
	{
		/*Loop 2: For each thread pool size ...*/
		for(j = 2, ret = 0; j <= 2*i; j *= 2, amfd = -1, lmfd = -1, ret = 0)
		{

		if(i != 256 && j != 2*i)
		{
			continue;
		}

#ifdef REPORT
		/*For each periodicity ... {120, 240, 480, 640, 1024} [ms]*/
		for(l = 0; l < NRPPa_MeasurementPeriodicity_ms2048; l++, amfd = -1, lmfd = -1, ret = 0)
		{
#endif
			/*Set argv: amf <UE_ctx file path> <npool>*/
			snprintf(buf, BUF_MAX, "/etc/init5g/amf/ue_ctx-%d.csv", i);
			snprintf(npool, 16, "%d", j);

			argvp[0] = BIN_AMF;
			argvp[1] = buf;
			argvp[2] = npool;
			argvp[3] = NULL;

			/*Starting AMF ...*/
			if((amfd = initProcess(argvp, envp, false)) < 0)
			{
				continue;
			}

			/*Waiting until n SIGUSR1 signals are catched (for n registered gNB)*/
			while(gnb < INIT_GNB)
			{
				pid_t tmp;

				/*Check if AMF is still alive (non-blocking)...*/
				if((tmp = waitpid(amfd, &ret, WNOHANG)) != 0)
				{
					if(tmp == amfd)
					{
						printf("[init5g] AMF is already terminated: SHUTDOWN\n");
						goto end;
					}
					else if(tmp < 0)
					{
						printf("[init5g] waitpid(2): %s\n", strerror(errno));
					}
				}

				pause();
			}
			sleep(1);

			if(kill(amfd, SIGUSR1) < 0)
			{
				dprintf(fd[0], "[init5g] UE assignment in AMF couldn't be triggered: %s\n", strerror(errno));
				goto next;
			}

#ifdef REPORT
			/*Set argv: lmf <ue> <npool> <period>*/
			explicit_bzero(buf, BUF_MAX);
			snprintf(buf, BUF_MAX, "%d", i);
			snprintf(period, 16, "%d", l);

			argvp[0] = BIN_LMF;
			argvp[1] = buf;
			argvp[2] = npool;
			argvp[3] = period;
			argvp[4] = NULL;
#else
			/*Set argv: lmf <ue> <npool>*/
			explicit_bzero(buf, BUF_MAX);
			snprintf(buf, BUF_MAX, "%d", i);

			argvp[0] = BIN_LMF;
			argvp[1] = buf;
			argvp[2] = npool;
			argvp[3] = NULL;
#endif

			/*Starting LMF here ...*/
			if((lmfd = initProcess(argvp, envp, false)) < 0)
			{
				goto next;
			}

			/*Loop 3: For each measurement iteration ~10,000*/
			iter_max = INIT_ITER;
			iter_max /= i;

			if(iter_max % i)
			{
				iter_max++;
			}

			for(k = 0; k < iter_max; k++, isPos = false)
			{
				sleep(1);

				/*Start positioning*/
				if(kill(amfd, SIGUSR2) < 0)
				{
					dprintf(fd[0], "[init5g] UE positioning in AMF couldn't be triggered: %s\n", strerror(errno));
					continue;
				}

				/*Waiting for finishing positioning (SIGUSR2 sent by AMF)*/
				pause();
				if(!isPos)
				{
					printf("[init5g] Positioning not completed\n");
				}
#ifdef DEBUG
				else
				{
					printf("[init5g] --- Positioning completed ---\n");
				}
#endif
			}

next:
			/*
			 * Send SIGTERM to AMF and LMF (process group) to invoke their signal handlers
			 *
			 * NOTE: The SIGTERM signal handler of this program is also invoked. It is used
			 *	 to reset the global gNB counter.
			 */
			if(kill(0, SIGTERM) < 0)
			{
				printf("[init5g] SIGTERM couldn't sent to AMF (%d) and LMF (%d): %s\n", amfd, lmfd, strerror(errno));
				fflush(NULL);
			}

			/*Get exit codes of terminated AMF and LMF from kernel*/
			pid_t pid;
			if((pid = wait(&ret)) < 0 || (lmfd > 0 && (pid = wait(&ret)) < 0))
			{
				printf("[init5g] wait(): %s\n", strerror(errno));
			}
#ifdef REPORT
		}
#endif

		}
	}

#else
	/*Loop 1: For each UE ...*/
	for(i = 2; i <= INIT_UE; i *= 2)
	{
		/*Loop 2: For each thread pool size ...*/
		for(j = 2, ret = 0; j <= 2*i; j *= 2, ret = 0)
		{

		/*
		 * Investigation of:
		 *
		 * (1) n_ue for n_pool = 2*n_ue
		 * (2) n_pool for n_ue = 256
		 */
		if(i != 256 && j != 2*i)
		{
			continue;
		}

#ifdef REPORT
		/*For each periodicity ... {120, 240, 480, 640, 1024} [ms]*/
                for(l = 0; l < NRPPa_MeasurementPeriodicity_ms2048; l++, ret = 0)
		{
#endif

			pid_t pid;

			/*Set argv: ./gnb <npool>*/
			explicit_bzero(npool, sizeof(npool));
			snprintf(npool, 16, "%d", j);
			argvp[0] = BIN_GNB;
			argvp[1] = npool;
			argvp[2] = NULL;
again:
			/*Starting gNB here ...*/
			if((pid = initProcess(argvp, envp, false)) < 0)
			{
				dprintf(fd[0], "[init5g] %s couldn't be started -- retry\n", BIN_GNB);
				goto again;
			}

retry:
			/*Waiting for termination of gNB*/
			if(wait(&ret) < 0)
			{
				dprintf(fd[0], "[init5g] wait(): %s\n", strerror(errno));
				goto retry;
			}

			if(WIFEXITED(ret))
			{
				if(WEXITSTATUS(ret) != EXIT_SUCCESS)
				{
					dprintf(fd[0], "[init5g] Child process %d (%s) exited with exit code %d\n", pid, BIN_GNB, WEXITSTATUS(ret));
					goto again;
				}
			}
			else
			{
				dprintf(fd[0], "[init5g] Child process %d (%s) exited unnormal -- retry\n", pid, BIN_GNB);
				goto again;
			}
#ifdef REPORT
		}
#endif
		}
	}
#endif

end:
	/*Poweroff system if init5g(1) shall terminate*/
	sync();
	sleep(3);
	if(syscall(SYS_reboot, LINUX_REBOOT_MAGIC1, LINUX_REBOOT_MAGIC2, LINUX_REBOOT_CMD_POWER_OFF, NULL) != 0)
	{
		perror("syscall()");
		return EXIT_FAILURE;
	}

	/*Never reached - in best case*/
	return EXIT_SUCCESS;
}
