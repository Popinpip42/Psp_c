#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

int	main()
{
	int pid;
	int fd[2];
	char buffer[100];

	pipe(fd);
	pid = fork(); //Creo dos procesos
	
	if (pid == 0)
	{
		char *msg = strdup("hola papa (proceso 2)");
		if (!msg)
			return (1);
		char *full_msg;
		int fd_2[2];
		pipe(fd_2);
		int pid_2 = fork(); //Creo un tercer proces
		if (pid_2 == 0)
		{
			char *msg2 = strdup(", dile esto también (proceso 3)");
			close(fd_2[0]);
			write(fd_2[1], msg2, 100);
		}else
		{
			close(fd_2[1]);
			wait(&pid_2);
			read(fd_2[0], buffer, 100);//--
			full_msg = malloc(strlen(msg) + strlen(buffer) * sizeof(char));
			if (!full_msg)
				return (1);
			//STRJOIN
			int i = 0;
			while (i < strlen(msg))
			{
				full_msg[i] = msg[i];
				i++;
			}
			int j = 0;
			while (j < strlen(buffer))
			{
				full_msg[i] = buffer[j];
				j++;
				i++;
			}
			full_msg[i] = '\0';
		}
		write(fd[1], full_msg, 100);
	}
	else
	{
		close(fd[1]);
		wait(&pid);
		read(fd[0], buffer, 100);
		printf("Qué dices hijo??? (proceso padre) \nHIJO: %s \n", buffer);
		close(fd[0]);
	}
}
