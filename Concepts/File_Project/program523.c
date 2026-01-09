#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int fd = 0,  iRet = 0;
    char Fname[100] = {'\0'};
    char Buffer[100] = {'\0'};
    int iSum = 0;

    printf("Enter the name of File: \n");
    scanf("%s", Fname);

    fd = open(Fname, O_RDWR);

    if(fd != -1)
    {
        printf("File successfully opened\n");

        printf("Data from file is : \n");
        while((iRet = read(fd, Buffer, sizeof(Buffer))) != 0)
        {
            // write(1, Buffer, iRet);
            iSum = iSum + iRet;

        }
        printf("File size of %d bytes\n", iSum);
        
        close(fd);
    }
    else
    {
        printf("There is no such file\n");
    }

    return 0;
}