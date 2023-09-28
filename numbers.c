#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int	main(void)
{
	int n;
	int pid = fork();

	if (pid != 0)
		n = 6;
	else
		n = 1;
	if (pid != 0)
		wait(NULL);
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", n);
		n++;
	}
	if (pid != 0)
		printf("\n");
}

