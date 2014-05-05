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
                exit(0);        /* dette er vores parent der exit'er */

        /* dette er child processen der fortsætter */
        setsid();       /* vi er nu session leader */
        chdir("/");     /* vi har brug for et working directory der ikke forsvinder */
        umask(0);       /* nulstil vores umask */

        /* hvis daemon'en har arvet nogle file descriptors, bør de lukkes nu */
        /*
                put kode her til at lukke fd's
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
