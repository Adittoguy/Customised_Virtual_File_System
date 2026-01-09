#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int fdSrc = 0, fdDest = 0;
    char fSource[100] = {'\0'};
    char fDest[100] = {'\0'};

    printf("Enter the name of Source file: \n");
    scanf("%s", fSource);

    printf("Enter the name of Destination file: \n");
    scanf(" %s", fDest);
    
    fdSrc = open(fSource, O_RDONLY);
    if(fdSrc == -1)
    {
        printf("Unable to open source file");
        return -1;
    }

    fdDest = creat(fDest, 0777);
    if(fdDest == -1)
    {
        printf("Unable to create destination file\n");
        return -1;
    }

    return 0;
}