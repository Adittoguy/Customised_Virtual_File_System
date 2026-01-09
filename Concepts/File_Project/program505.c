#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int fd = 0;

    fd = open("./LB.txt", O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open file");
    }
    else
    {
        printf("File get succussfully opened with fd : %d", fd);
        write(fd, "Jay Ganesh", 10);
        close(fd);
    }

    return 0;
}