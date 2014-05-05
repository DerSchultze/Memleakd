#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>


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
init_as_daemon();

while  ((p=malloc(1024*1024))) {
	//printf("%d\n",i++);
	p[0]=0;
	}


sleep(100);
return 0;
}
