#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int fd = 0;
    int iRet = 0;
    char Buffer[100] = {'\0'};

    fd = open("./JanuaryX.txt", O_RDONLY);

    if(fd != -1)
    {
        printf("File gets opened with Fd: %d\n", fd);

        iRet = read(fd, Buffer, 11);

        printf("Data from file is: %s\n", Buffer);

        close(fd);
    }

    return 0;
}