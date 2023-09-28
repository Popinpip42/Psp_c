#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int	main(int argc, char **argv)
{
	int fp;
	//char *saludo = strdup("Un saludo\n");
	char *saludo = strdup(argv[1]);
	/*char	*saludo;
	
	if (argc != 2)
	{
		printf("error de parametros\n");
		return (1);
	}
	int i = 0;
	while (argv[1][i])
		i++;
	saludo = (char *)malloc((i + 1) * sizeof(char));
	if (!saludo)
		return (2);
	//strncpy(saludo, argv[1], strlen(argv[1]) + 1);
	//saludo[i] = '\0';
	//STRLCPY
	i = 0;
	while (argv[1][i])
	{
		saludo[i] = argv[1][i];
		i++;
	}
	//saludo[i] = '\0';
	*/
	fp = open("FIFO3", O_WRONLY); //or 1 -> Escritura
	if (fp == -1){
		printf("Error al abrrir fichero desde writer\n");
		exit(1);
	}
	
	write(fp, saludo, strlen(saludo));
	write(fp, "\n", 2);
	close(fp);
	free(saludo);
	return (0);
}
