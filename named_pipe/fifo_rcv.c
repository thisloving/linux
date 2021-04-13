#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

#define FIFO "/tmp/fifo"

int main()
{
	char buffer[80];
	int fd;
	int n;
	char info[80];
	fd = open(FIFO, O_RDONLY);
	n = read(fd, buffer, 80);
	if (n < 0) {
		perror("read error");
		return -1;
	}

	printf("buffer=%s\n", buffer);
	close(fd);
	
	return 0;
}
