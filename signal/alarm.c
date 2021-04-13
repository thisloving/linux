#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void handler() {
	printf("hello\n");
}

int main()
{
	int i;
	int time;
	signal(SIGALRM, handler);
	alarm(3);
	for (i = 0; i < 5; i++) {
		printf("sleep %d ...\n", i);
		sleep(1);
	}

	alarm(3);
	sleep(2);

	time = alarm(0);
	printf("time = %d\n", time);
	for (i = 0; i < 3; i++) {
		printf("sleep %d ...\n", i);
		sleep(1);
	}

	return 0;
}
