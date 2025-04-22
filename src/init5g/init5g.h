/*
 * init5g - init program to intialize system and start 5G components
 *
 * created on: 08/06/2024, NK
 * last modified: 08/11/2024, NK
 *
 * NOTE: This program can compiled for usage as 5G core system by
 *	 definition of the macro "CORE". Otherwise it is compiled
 *	 to execute a gNB daemon.
 */
#ifndef _INIT5G_H_
#define _INIT5G_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <time.h>
#include <linux/reboot.h>
#include <sys/syscall.h>

#ifdef REPORT
	#include <nrppa/NRPPa_MeasurementPeriodicity.h>
#endif
/*
 * Macros
 *
 * @BIN_XXX: path of used binaries
 * @ENV_XXX: environment variables
 * @INIT_LOG: target log file
 * @INIT_VER: current version of this init system
 */
#define BIN_SH "/bin/sh"
#define BIN_INIT "/usr/local/bin/init"

#ifdef CORE
	#define BIN_AMF "/usr/local/bin/amfd"
	#define BIN_LMF "/usr/local/bin/lmfd"
#else
	#define BIN_GNB "/usr/local/bin/gnb"
#endif

#define ENV_PATH "PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin"
#define ENV_PWD "PWD=/"
#define ENV_LDPATH "LD_LIBRARY_PATH=/usr/local/lib:/usr/lib:/lib"
#define ENV_SIZE 4

#define ARGV_SIZE 10
#define BUF_MAX 128

#define INIT_LOG "/var/log/init5g.log"
#define INIT_GNB 1
#define INIT_UE 256
#define INIT_TPOOL 512
#define INIT_ITER 10000

#ifndef INIT_VER
	#define INIT_VER "0.3.0"
#endif

#endif
