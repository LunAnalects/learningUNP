
#include "utility.h"          /* Declares function defined here */

/* Return a string containing the current time formatted according to
   the specification in 'format' (see strftime(3) for specifiers).
   If 'format' is NULL, we use "%c" as a specifier (which gives the'
   date and time as for ctime(3), but without the trailing newline).
   Returns NULL on error. */

void 
print_socket(void *addrptr)
{
    struct sockaddr_in *saddr = addrptr;
    char buf[50];
    printf("----------\nsocket: \nPort(n):%hu\nPort(h):%hu\nAddr:%s\n----------\n",
        saddr->sin_port, 
        ntohs(saddr->sin_port),
        inet_ntop(saddr->sin_family, &(saddr->sin_addr), buf, 50)
        );
}


char *
curr_time(const char *format,char *buf, const size_t BUF_SIZE)
{
    //static char buf[BUF_SIZE];  
    /* caller offers the buffer */
    if(buf == NULL)
        return NULL;
    
    time_t t;
    size_t s;
    struct tm *tm;

    t = time(NULL);
    tm = localtime(&t);
    if (tm == NULL)
        return NULL;

    s = strftime(buf, BUF_SIZE, (format != NULL) ? format : "%T", tm);

    return (s == 0) ? NULL : buf;
}
