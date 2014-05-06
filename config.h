#ifndef CONFIG_H
#define CONFIG_H

#include <stdbool.h>

//Misc shit
#define PROC_VERSION "0.1"
#define CONFIG_FILE  "memleakd.conf"
#define BUFFER_SIZE 256

// Syslog related stuff
#define APP_NAME "mamleakd"

//Configuration stuff
struct config_params {
        int     maxthreads;
        void    *firstblock;
        bool    ismaster;
        char    pid_file[BUFFER_SIZE];
};

struct config_line {
	char	var[BUFFER_SIZE];
	char	val[BUFFER_SIZE];
	int	line_nr;
};

extern struct config_params*   cfg;
typedef struct config_params *pconf;
pconf read_config(void);

#endif	/* CONFIG_H */
