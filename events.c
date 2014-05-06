#include <sys/time.h>
#include <sys/timeb.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include "events.h"


	extern unsigned long long int  	last_utime, cur_utime;
	struct timeval			rawtime, nextlogtime;
        int                      exit_now;


void get_utime(unsigned long long int *utime)
{
	long long int		temp;

	gettimeofday(&rawtime,NULL);
	temp = rawtime.tv_sec;
	temp = (temp * 1000000) + rawtime.tv_usec;
	*utime = temp;

}

void do_loggin()
{	
}

void term_handler()
{
	exit_now = 1;
}

void hup_handler()
{
}


