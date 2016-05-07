//Pure C prog#include "server.h"
#include "server.h"

#define SERV_PORT (19999)
#define BACK_LOG (5)
#define MAX_BUF 1024

int 
main(int argc, char *argv[])
{
    int lstnid, cnntid;
    struct sockaddr_in cliaddr, servaddr;
    socklen_t clilen;
    lstnid = socket(AF_INET, SOCK_STREAM, 0);
    memset(&servaddr, 0,  sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);


    char buffer[MAX_BUF];

    bind(lstnid, (const struct sockaddr *)&servaddr, sizeof(servaddr));
    printf("listening:\n");
    listen(lstnid, BACK_LOG);

    int childpid;
    printf("listening: passed\n");
    curr_time("%T", buffer, MAX_BUF);
    printf("[%s, %d]\n",buffer, lstnid);
    print_socket( &servaddr );
    for(;;)
    {
        clilen = sizeof(cliaddr);
        cnntid = accept(lstnid,  (struct sockaddr *)&cliaddr, &clilen);
        printf("Accepted!Client:\n");
        print_socket(&cliaddr);

        if( (childpid = fork() == 0) )
        {
            close(lstnid);
            printf("connected!, now in childpid: %d . cnntid: %d \n", getpid(),cnntid );
            //str_recv(cnntid, buffer, MAX_BUF);
            /*
            do server jobs
            */
            while(recv(cnntid, buffer,1,0) == 1);
            printf("I'm out!\n");
            //close(cnntid);
            exit(0);
        }
        close(cnntid);
    }

    return 0;
}
