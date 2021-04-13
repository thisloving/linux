#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void new_op(int, siginfo_t*, void*);

int main(int arhc, char* argv[])
{
	struct sigaction act;
	int sig;
	sig = atoi(argv[1]);
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = new_op;

	if (sigaction(sig, &act, NULL) < 0) {
		perror("install signal error");
		return -1;
	}

	while(1) {
		sleep(2);
		printf("Wait for the signal\n");
	}

	return 0;
}

void new_op(int signum, siginfo_t* info, void* myact) {
	printf("reveive signal %d\n", signum);
	sleep(5);
}
