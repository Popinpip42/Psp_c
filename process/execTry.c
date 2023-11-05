#include <stdio.h>
#include <unistd.h>

int	main()
{
	int	n = execl("/bin/ls", "ls", "-l", (char *) NULL);
	if (n == -1)
		printf("Error");
}
