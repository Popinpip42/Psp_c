#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int	main()
{
	int	pid = fork();

	if (pid != 0)
		fork();
	printf("Hello World\n");
	fflush(NULL);
	wait(NULL);
}
