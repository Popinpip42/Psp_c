#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct	s_targs {
	int	size;
	int	**nums;
} t_targs;

void* routine(void* arg)
{
	t_targs*	args = (t_targs*)arg;
	int		size = args->size;
	int		*nums = *(args->nums);
	int		result = 0;
	for (int i= 0; i < size; i++)
	{
		printf("%d\n", *(nums + i));
		result += *(nums + i);
	}
	printf("RES: %d\n", result);
	return (NULL);
}

int main(int argc, char* argv[])
{
	int		result;
	int		num_threads = 2;
	pthread_t	threads[num_threads];
	int		*nums; //Array of nums
	int		nums_size; //Random Size
	
	srand(time(NULL));
	nums_size = (rand() % MAX_SIZE) + 1 ;
	if (!(nums = malloc(nums_size * sizeof(int))))
		return (1);
	printf("**Arr size: %d\n", nums_size);
	for (int i = 0; i < nums_size; i++)
	{
		nums[i] = (rand() % MAX_SIZE) + 1;
		printf("%d", nums[i]);
		if (i != nums_size - 1)
			printf(", ");
	}
	printf("\n**Creating threads...\n");

	int	*subarray;
	int	*subarray2;
	int	subarray_size;
	int	subarray_size2;
	subarray_size =  nums_size / 2;
	printf("size subarray: %d\n", subarray_size);
	subarray_size2 = nums_size - subarray_size;
	printf("size subarray2: %d\n", subarray_size2);
	if (!(subarray = malloc(subarray_size * sizeof(int))))
		return (2);
	if (!(subarray2 = malloc(subarray_size2 * sizeof(int))))
		return (3);
	memmove(subarray, nums, subarray_size * sizeof(int));
	memmove(subarray2, nums + subarray_size, subarray_size2 * (sizeof(int))); 
	
	t_targs arg1;
	arg1.size = subarray_size;
	arg1.nums = &subarray;
	if (pthread_create(threads + 0, NULL, routine, &arg1) != 0)
	       perror("pthread_create");
	pthread_join(threads[0], NULL);
	
	t_targs arg2;
	arg2.size = subarray_size2;
	arg2.nums = &subarray2;
	if (pthread_create(threads + 1, NULL, routine, &arg2) != 0)
	       perror("pthread_create");
	pthread_join(threads[1], NULL);
	/*for (int i = 0; i < num_threads; i++)
	{
		pthread_join(threads[i], NULL);
	}*/

	free(subarray);
	free(subarray2);
	free(nums);
}
