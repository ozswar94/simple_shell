#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid_fils;
	int status = 0;

	pid_fils = fork();
	if (pid_fils == -1)
	{
		fprintf(stderr, "fork() impossible, errno=%d\n", errno);
		return 1;
	}
	if (pid_fils == 0)
	{
		fprintf(stdout, "Fils : PID=%d, PPID=%d\n", getpid(), getppid());
		return 0;
	}
	else
	{
		wait(&status);
		fprintf(stdout, "Pere : PID=%d, PPID=%d\n", getpid(), getppid());
		return 0;
	}
	return 0;
}
