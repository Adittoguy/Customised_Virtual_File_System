#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int fd = 0;
    int iRet = 0;
    char Arr[] = "Pune";

    fd = open("./JanuaryX.txt", O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open file");
    }
    else
    {
        printf("File get succussfully opened with fd : %d\n", fd);

        iRet = write(fd, Arr, 3);

        printf("%d bytes gets successfully gets returned into file\n", iRet);
        
        close(fd);
    }

    return 0;
}