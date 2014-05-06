#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include "events.h"


int	i;
int	*p;

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
        FILE                    *logfd;

	init_as_daemon();

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


sleep(100);
return 0;
}
