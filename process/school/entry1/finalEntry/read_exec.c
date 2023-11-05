#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 1024

int	get_next_line(int fd, char **buffer);

int	main(void)
{
	int	bytes_read;
	//char	*buff = NULL;
	char	buff[BUFF_SIZE];

	int	nums[2];
	int	nums_size;
	int	index;

	nums_size = sizeof(nums) / sizeof(*nums);
	
	while ((bytes_read = read(0, &buff, 10)) != -1) //&& index < nums_size)
	{
		index = 0;
		printf("Read...: ");
		while (buff[index] != '\0' && buff[index] != '\n')
		{
			printf("%c", buff[index]);
			index++;
		}
		printf("\n");
	}
}

