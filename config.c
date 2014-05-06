#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <malloc.h>

#include "config.h"

pconf read_config() {
	FILE*	fp;
 	//pconf	conf = (struct config_params*)malloc(sizeof(struct config_params));
 	pconf	conf = NULL;
	char	linein[BUFFER_SIZE];
	unsigned int	i;
	char	argument[BUFFER_SIZE];
	char	parameter[BUFFER_SIZE];
	char	*p;

	fp = fopen(CONFIG_FILE, "r");
	//printf("buffersize: %d\n",BUFFER_SIZE);

	if (fp != NULL) {
		conf = malloc(sizeof(struct config_params));
		bzero(conf,sizeof(conf));

		/* Ensure sane values, for certain paramaters, in case they should be undefined */
		conf->maxthreads = 1;

		while (fgets(linein,BUFFER_SIZE,fp)) {
			p = linein;
			i = 0;
			bzero(parameter,sizeof(parameter));
			bzero(argument,sizeof(argument));
			for (i=0; (i < strlen(linein)) && (linein[i] != 9); i++);
			strncpy(parameter,p,i);
			for (; (i < strlen(linein)) && (linein[i] == 9); i++);
			p = p + i;
			strcpy(argument,p);
			argument[strlen(argument)-1] = 0;
			//printf("*%s*-*%s*\n",parameter,argument);
			if (strcmp(parameter,"pid_file") == 0) {
				strcpy(conf->pid_file,argument);
			}
			if (strcmp(parameter,"maxthreads") == 0) {
				conf->maxthreads = atoi(argument);
			}
		} 
		fclose(fp);
	} else {
		//printf("Blah!");
	}
	return (conf);
}
