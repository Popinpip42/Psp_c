#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int	main(void)
{
	pid_t	pid;
	int	fd[2];

	if (pipe(fd) == -1)
		return 1;
	if ((pid = fork()) == -1)
		return 2;

	if (pid == 0)
	{
		close(fd[1]);
		if (dup2(fd[0], 1) == -1)
			return 3;
		close(fd[1]);
		execl("./a.out", "./a.out", NULL);
	}
	else
	{
		/*close(fd[0]);
		char	buff[129];
		int	bytes_read;

		while ((bytes_read = read(0, &buff, sizeof(buff))) > 0)
		{
			buff[bytes_read] = '\0';
			write(fd[1], buff, strlen(buff));
		}
		close(fd[1]);*/
		close(fd[0]); // Close the read end of the pipe
		char buff[129];
		int bytes_read;
		int newline_found = 0;

		while ((bytes_read = read(0, buff, sizeof(buff) - 1)) > 0) {
			buff[bytes_read] = '\0';

			if (strchr(buff, '\n') != NULL) {
				newline_found = 1;
				bytes_read = strchr(buff, '\n') - buff + 1; 
			}
			write(fd[1], buff, bytes_read);
			if (newline_found) {
				break;
			}
		}
		close(fd[1]);
		wait(NULL);
	}
}
