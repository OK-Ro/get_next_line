#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int fd;
	int fileoped;
	char buffer[42];

	fd = open("file2.txt", O_RDONLY);
	
	while (fileoped = read(fd, buffer, 42) > 0)
	{
		printf("%s", buffer);
	}
	close(fd);
}