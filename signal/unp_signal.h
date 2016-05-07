#include <signal.h>

typedef void signal_fun(int);

signal_fun *
unp_signal(int signo, signal_fun *funct);