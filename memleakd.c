#include <stdlib.h>

int	i;
int	*p;


main()
{
while  (p=malloc(1024*1024)) {
	printf("%d\n",i++);
	p[0]=0;
	}


sleep(100);
}
