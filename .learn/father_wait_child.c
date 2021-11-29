#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	int i = 0;
	int status;
	pid_t child;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	while (i < 5)
	{
		child = fork();
		if (child == 0)
		{
			printf("Child Number = %d, PID=%d, PPID=%d\n", i + 1, getpid(), getppid());
			execve(argv[0], argv, NULL);
		}
		else
		{
			wait(&status);
			printf("In Processus Father, PID=%d\n", getpid());
			i++;
		}
	}
	return (0);
}
