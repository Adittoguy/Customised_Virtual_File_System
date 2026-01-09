#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int fd = 0;

    //O_RDONLY,  O_WRONLY,   O_RDWR,     O_TRUNC    O_CREAT   O_APPEND

    fd = open("./LB.txt", O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open file");
    }
    else
    {
        printf("File get succussfully opened with fd : %d", fd);
    }

    return 0;
}