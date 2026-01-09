#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int fd = 0;

    fd = open("./January.txt", O_RDWR | O_CREAT, 0777);

    if(fd == -1)
    {
        printf("Unable to open file");
    }
    else
    {
        printf("File get succussfully opened with fd : %d", fd);
        write(fd, "Jay Ganesh", 3);
        close(fd);
    }

    return 0;
}