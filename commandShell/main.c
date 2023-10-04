#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

int	main(void)
{
	int	fd[2];
	int	bfr_size = 192;
	int	bytes_r;
	pid_t	pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		char	response[bfr_size];
		close(fd[1]);
		while (1)
		{
			while ((bytes_r = read(fd[0], response, bfr_size)) > 0){
				response[bytes_r] = '\0';
				if (strlen(response) != 0)
				{
					printf("Response recieved-> %s\n", response);
					fflush(stdout);
				}
			}
		}
		close(fd[0]);

	}else{
		close(fd[0]);
		char	command[bfr_size];
		int	written = 0;

		while (1)
		{
			while ((bytes_r = read(STDIN_FILENO, command, bfr_size)) > 0)
			{
				command[bytes_r] = '\0';
				if (written = write(fd[1], command, strlen(command)))
				{
					perror("write");
					break;
				}
			}
		}
		close(fd[1]);
		wait(&pid);
	}
	
}
