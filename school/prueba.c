#include <unistd.h>

int	main(void)
{
	execl("./a.out", "./a.out", NULL);
}
