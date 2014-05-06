#ifndef EVENTS_H
#define EVENTS_H

extern int                      exit_now;

void do_loggin();
void get_utime(unsigned long long int *utime);
void term_handler();
void hup_handler();

#endif	/* EVENTS_H */
