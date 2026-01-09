#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int fd = 0,  iRet = 0;
    char Fname[100] = {'\0'};

    printf("Enter the name of File: \n");
    scanf("%s", Fname);

    fd = open(Fname, O_RDWR, 0777);

    if(fd != -1)
    {
        printf("File successfully opened\n");

        close(fd);
    }
    else
    {
        printf("There is no such file\n");
    }

    return 0;
}