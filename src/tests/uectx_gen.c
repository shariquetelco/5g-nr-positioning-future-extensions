/*
 * uectx_gen - generate random UE contexts for AMF
 *
 * NOTE: While generation, identical IMSI values are not checked!
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define SRC_FILE "../ue_ctx.csv"

int
main()
{
	int fd, i;
	char buf[100] = {0};

	if((fd = open(SRC_FILE, O_RDWR | O_APPEND)) < 0)
	{
		perror("open(2)");
		return EXIT_FAILURE;
	}

	srand(time(NULL));

	/*Generate entry line for UE context*/
	for(i = 5; i < 256; i++)
	{
		/*Generate random IMSI ending*/	
		snprintf(buf, 99, "imsi-00101%.10d,%d,%d,%d\n", rand()+100, i+1, i, i);
		write(fd, buf, strlen(buf));
	}

	close(fd);

	return EXIT_SUCCESS;
}
