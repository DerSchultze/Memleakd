CC = gcc
CCFLAGS := -W -Wall -ggdb
APPNAME = memleakd
OBJECTS = memleakd.o events.o config.o


all :	${OBJECTS}
	${CC} ${CCFLAGS} ${LDFLAGS} -o ${APPNAME} ${OBJECTS}


memleakd.o : memleakd.c
	${CC} ${CCFLAGS} -c memleakd.c

events.o : events.c
	${CC} ${CCFLAGS} -c events.c

config.o : config.c
	${CC} ${CCFLAGS} -c config.c

clean :
	rm -f ${APPNAME}
	rm -f a.out
	rm -f *.o
	rm -f *~
