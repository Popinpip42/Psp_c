#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define BFFR_SIZE 100

int	main(void)
{
	int fp;
	int p;
	int bytesLeidos;
	char buffer[BFFR_SIZE];
	
	p = mknod("FIFO3", S_IFIFO | 0666, 0);
	if (p == -1){
		printf("Error en mknod\n");
		exit(1);
	}
	while (1){
		fp = open("FIFO3", O_RDONLY); // or 0 -> Read Only
		if (fp == -1)
			exit(2);
		while ((bytesLeidos = read(fp, buffer, BFFR_SIZE)) >  0 ){
			buffer[bytesLeidos] = '\0';
			printf("%s", buffer);
			fflush(NULL);
		}
		close(fp);
	}
}
