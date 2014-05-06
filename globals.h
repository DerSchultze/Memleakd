#define CONFIG_FILE memleakd.config

extern struct config_container {
	int	maxthreads;
	void	*firstblock;
	bool	ismaster;
}

