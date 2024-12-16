#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = open("test.txt",O_CREAT | O_RDWR, 0777);

    char buffer[13];

    write(fd, "ilias elmahi 1337", sizeof("ilias elmahi 1337"));
    read(fd, buffer, 13);
    printf("%s\n",buffer);
}
