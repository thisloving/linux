#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;
	int status;

	pid = fork();
	if (0 == pid) {
		printf("Hi I am child process!\n");
		sleep(10);
	} else if (pid > 0) {
		printf("send signal to child process(%d)\n", pid);
		sleep(1);
		kill(pid, SIGABRT);
		wait(&status);
		if (WIFSIGNALED(status)) {
			printf("child process receive signal %d. status:%d\n", WTERMSIG(status), status);
		}
	} else {
		perror("fork error");
		return -1;
	}

	return 0;
}
