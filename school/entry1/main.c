#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	bytesRead;
	char	buffer;

	int	num = 0;
	char	current_char;
	int	nums[2];
	
	int	index = 0;
	int	size = sizeof(nums) / sizeof(nums[0]);
	int	flag = 0;
	while (index < size && (bytesRead = read(0, &buffer, 1)) > 0)
	{
		//printf("Recieved: %c\n", buffer);
		current_char = buffer;
		
		if (current_char >= '0' && current_char <= '9')
		{
			num = num * 10 + (current_char - '0');
			flag = 1;
		}
		else if (current_char == ' ' || current_char == '\n')
		{
			if (flag)
			{
				nums[index] = num;
				index++;
				num = 0;
				flag = 0;
			}
		}else{
			printf("Invalid Input: Not a number\n");
			break;
		}
	}
	//TODO: Send nums[2] to another program
	//write(fd[x], nums, sizeof(nums));
	//execl(process2, nums[0], nums[1]);
	int	result = 0;
	for (int i = 0; i < size; i++)
	{
		result += nums[i];
	}
	printf("RESULT: %d\n", result);
}
