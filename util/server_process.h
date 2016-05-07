#ifndef UNP_SERVER_PROCESS_H
#define UNP_SERVER_PROCESS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

void 
err_sys(const char* x);

ssize_t 
readn(int id, void *buf, size_t n);

ssize_t 
writen(int id, const void *buf, size_t n);

ssize_t 
readline(int id, void *buf, size_t maxlen);

ssize_t 
writeline(int id, const void *buf, size_t maxlen);

void 
str_echo(int sockfd);

void 
str_recv(int sid, char* buffer, const size_t BUF_MAX);

void 
str_send(int sid, char* src, unsigned int len);

#endif
