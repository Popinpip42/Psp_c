#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void) {
	int fd[2];
	pid_t pid;

	if (pipe(fd) == -1) {
		perror("pipe");
		return 1;
	}
	if ((pid = fork()) == -1) {
		perror("fork");
		return 2;
	}

	if (pid == 0) {
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1) {
			perror("dup2");
			return 3;
		}
		close(fd[0]);
		execl("./a.out", "./a.out", NULL);
		perror("execl");
		return 4;
	}
	else 
	{
		close(fd[0]);
		char input[] = "12 34\n";
		if (write(fd[1], input, strlen(input)) == -1) {
			perror("write");
			return 5;
		}
		close(fd[1]);
	}
	return 0;
}
