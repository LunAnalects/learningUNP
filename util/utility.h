#ifndef UNP_UTILITY_H
#define UNP_UTILITY_H
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

void 
print_socket(void *addrptr);

char *
curr_time(const char *format,char *buf, const size_t BUF_SIZE);


#endif 