#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <libft.h>

#define N 10
#define E 2
#define S 2

int	id = 1;

typedef struct	s_car {
	int	id;
}	t_car;

int	gen_rand_cars(t_list **queue){
	srand(time(NULL));
	int	n = (rand() % N) ;
	//printf("Random: %d\n", n);
	if (!n) return (0);
	int	i = 0;
	while (i < n)
	{
		t_car *car = (t_car *)malloc(sizeof(car));
		if (!car) return (-1);
		car->id = id++;
		ft_lstadd_back(queue, ft_lstnew((void *)car));	
		//printf("added car\n");
		i++;
	}
	return (i);
}

void esperar_llegada();
void elevar_barrera();

int	main(){
	t_list	*entry_queue = NULL;
	int cars = gen_rand_cars(&entry_queue);
	printf("Generated cars: %d\n", cars);
	//list iteration
	/*if (cars != 0){
		//printf("%d\n", ((t_car *)entry_queue->content)->id);
		while (entry_queue != NULL){
			printf("%d\n", ((t_car *)entry_queue->content)->id);
			entry_queue = entry_queue->next;
		}
	}*/
	printf("Entradas %d, Salidas %d\n", E, S);

}
