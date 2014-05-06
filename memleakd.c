#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include "events.h"
#include "config.h"


int	i;
int	*p;
pconf	cfg = NULL;

int init_as_daemon(void) {
        pid_t   pid;

        if ((pid = fork()) < 0)
                return(-1);
        else if (pid != 0)
                exit(0);        /* Parrent exits here */

        /* The child continues */
        setsid();       /* Set session leader */
        chdir("/");     /* We need a stable WD */
        umask(0);       /* Clear umask */

        /* If the daemon has inherited some file descriptors, these should be closed now */
        /*
                Close fd's
        */

        return 0;
}


int main()
{
	struct                  sigaction saio;
        sigset_t                sigset;
//        FILE                    *logfd;

	cfg = read_config();
        if (cfg == NULL) {
                fprintf(stderr,"\nRead config epic fail!\n");
        //        clean_shutdown();
                return(1);
        } else {
		printf("Read config\nmaxthreads = %d\nchunksize = %d\n",cfg->maxthreads,cfg->chunksize);
	}

        if (init_as_daemon() == -1) {
                fprintf(stderr, "\nUnable to init as daemon - fork failed\n");
                exit(1);
        }

        /* Registering the handler, catching SIGTERM and SIGHUP signals */
        sigemptyset(&sigset);
        saio.sa_mask = sigset;
        saio.sa_flags = 0;
        saio.sa_restorer = NULL;

        saio.sa_handler = term_handler;
        sigaction(SIGTERM,&saio,NULL);


while  ((p=malloc(1024*1024))) {
	//printf("%d\n",i++);
	p[0]=0;
	}


sleep(10);
return 0;
}
