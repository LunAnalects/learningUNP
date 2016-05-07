#include "client.h"

#define PORT 19999
#define BUF_MAX 100
int main(int argc, char *argv[])
{
    struct sockaddr_in cliaddr, servaddr;

    memset(&cliaddr, 0, sizeof(cliaddr));
    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr.s_addr);
    print_socket(&servaddr);

    char buffer[BUF_MAX];
    char *str_b = buffer;
    int childid;
    for(int i = 0; i < 10; ++i)
    {
        printf("loop: %d\n",i);
        childid = fork();
        if( childid == 0 )
        {
            int sid = socket(AF_INET, SOCK_STREAM, 0);
            printf("sid:%d connecting\n",sid);
            connect(sid, (struct sockaddr *) &servaddr, sizeof(servaddr));
            sprintf(str_b, "--this is a message from sid: %d. childid:%d", sid, childid);
            unsigned int len_s = strlen(str_b);
            printf("len:%d\n",len_s);
            str_send(sid, str_b, len_s);
            printf("send finished\n");
            close(sid);
            return 0;
        }

    }
    printf("--------------Parent Finishing\n");


    return 0;
}
