#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int fd = 0;
    fd = creat("./LB.txt", 0777);

    printf("FD is : %d", fd);

    return 0;
}