#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = open("yassin", O_CREAT | O_RDWR, 0666);

    dup2(fd,1);
    printf("hello hi");
    write(1, "d", 1);
}
