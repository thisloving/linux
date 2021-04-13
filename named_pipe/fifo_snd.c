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
	int ret;
	char info[80];
	unlink(FIFO);

	ret = mkfifo(FIFO, 0600);
	if (ret) {
		perror("mkfifo error");
		return -1;
	}

	memset(info, 0x00, sizeof(info));
	strcpy(info, "happy new year!");
	fd = open(FIFO, O_WRONLY);
	n = write(fd, info, strlen(info));
	if (n < 0) {
		perror("write error");
		return -1;
	}

	close(fd);
	return 0;
}
