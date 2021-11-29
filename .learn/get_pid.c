#include <stdio.h>
#include <unistd.h>

int main(void)
{
	printf("PID=%u, PPID=%u\n", getpid(), getppid());
	return 0;
}
