#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int	main(void)
{
	int n = 5;

	while (n--)
	{
		pid_t pid = fork();

		if (pid == 0)
		{
			printf("myid: %d\n", getpid());
			fflush(stdout);
			exit(0);
		}
		fflush(stdout);
		fflush(stdin);
	}
	return (0);
}
