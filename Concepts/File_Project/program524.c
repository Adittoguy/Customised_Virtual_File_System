#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int fd = 0,  iRet = 0;
    char Fname[100] = {'\0'};
    char Buffer[100] = {'\0'};
    int iCnt = 0;
    int iCount = 0; 

    printf("Enter the name of File: \n");
    scanf("%s", Fname);

    fd = open(Fname, O_RDWR);

    if(fd != -1)
    {
        printf("File successfully opened\n");

        printf("Data from file is : \n");

        while((iRet = read(fd, Buffer, sizeof(Buffer))) != 0)
        {
            for(iCnt = 0; iCnt < iRet; iCnt++)
            {
                if(Buffer[iCnt]== 'a')
                {
                    iCount++;
                }
            }
        }

        printf("Total number of a are : %d\n", iCount);
        
        close(fd);
    }
    else
    {
        printf("There is no such file\n");
    }

    return 0;
}