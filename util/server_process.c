#include "server_process.h"

#define MAX_LINE 1024

void 
err_sys(const char* x) 
{ 
    perror(x); 
    exit(1); 
}


ssize_t 
readn(int id, void *buf, size_t n)
{
    size_t  nleft;
    ssize_t nread;
    char    *ptr = buf;

    nleft = n;

    while( nleft > 0 )
    {
        if ( (nread = read(id, ptr, nleft)) < 0 )
        {
            if (errno == EINTR)
                nread = 0;
            else
                return (-1);
        }
        else if (nread == 0)
            break;

        nleft -= nread;
        ptr +=nread;
    }

    return (n - nleft);
}

ssize_t 
writen(int id, const void *buf, size_t n)
{
    size_t      nleft;
    ssize_t     nwritten;
    const char  *ptr;
    ptr = buf;
    nleft = n;

    while(nleft > 0)
    {
        if( (nwritten = write(id, ptr, nleft)) < 0 )
        {
            if (nwritten < 0 && errno == EINTR)
                nwritten = 0;
            else
                return (-1);
        }

        nleft -= nwritten;
        ptr +=   nwritten;
    }

    return (n);
}

void 
str_echo(int sockfd)
{
    char buf[MAX_LINE];
    ssize_t n;
  again:
    while( (n = read(sockfd, buf, MAX_LINE)) > 0)
    {
    	send(sockfd, buf, n, 0);
    }

    if( n < 0 && errno == EINTR)
    	goto again;
    else if ( n < 0 )
    	err_sys("str_echo: read error");

}
/*
receive and send bytes stream whose first two bytes containing length information
*/
void 
str_recv(int sid, char* buffer, const size_t BUF_MAX)
{
    recv(sid, buffer, 2, 0);
    unsigned short comming_len = ntohs(*(unsigned short *)buffer);
    printf("coming_len: %hu\n",comming_len);
    if(comming_len < BUF_MAX - 1)
        recv(sid, buffer, comming_len,0);
    buffer[comming_len] = 0;
    printf("The message: %s \n", buffer);

}

void 
str_send(int sid, char* src, unsigned int len)
{
	unsigned int nlen = htons(len);
	send(sid, &nlen, 2, 0);
	send(sid, src, len, 0);
	printf("Sending....\nLength: %hu",len);
}



