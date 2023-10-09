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

	int	nums[2];
	int	nums_size;
	int	index;

	nums_size = sizeof(nums) / sizeof(*nums);
	index = 0;
	while ((bytes_read = get_next_line(0, &buff)) != -1) //&& index < nums_size)
	{
		printf("%s\n", buff);
		printf("reading\n");

		free(buff);
		if (buff == NULL)
			printf("IS NULL\n");
		else
			printf("faile to null\n");
		fflush(stdin);
	}
}

int	get_next_line(int fd, char **buffer)
{
	int	n_read;
	int	ch;
	int	i;

	if ((*buffer = (char *)malloc(BUFF_SIZE * sizeof(char))) == NULL)
	{
		printf("MALLOC\n");
		return (-1);
	}
	i = 0;
	while ((n_read = read(fd, &ch, 1)) > 0)
	{
		printf("here\n");
		if (ch == '\n')
		{
			(*buffer)[i] = '\0';		
			//printf("%ld\n", strlen(*buffer));
			return (strlen(*buffer));
		}
		else
		{
			(*buffer)[i] = ch;
			i++;
		}
	}
	free(*buffer);
	printf("%d\n", n_read);
	return (n_read);
}

