#include "client.h"


#define PORT 19999
#define BUF_MAX 100
int main(int argc, char *argv[])
{
    int sid = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in cliaddr, servaddr;

    memset(&cliaddr, 0, sizeof(cliaddr));
    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr.s_addr);
    print_socket(&servaddr);
    printf("connecting...\n");
    int connect_state = connect(sid, (struct sockaddr *) &servaddr, sizeof(servaddr));
    printf("connected....state:%d\n", connect_state);
    char buffer[BUF_MAX];
    char *str_b = buffer;
    str_b = "sb, this is a message";
    unsigned int len_s = strlen(str_b);
    str_send(sid, str_b, len_s);
    printf("finishing");


    return 0;
}
