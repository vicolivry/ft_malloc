#include "includes/ft_malloc.h"

int main(void)
{
	int	i = 0;

	char*str;
	void *ptr;
	void *ptr2;
	void *ptr3;

	while (i++ < 200)
	{
		str = (char*)malloc(10);
		ft_print("PRE ASSIGN str[0]\n");
		str[0] = 'a';
		ft_print("POST ASSIGN str[0]\n");
		str[1] = '\n';
		str[2] = '\0';
	}
	// ptr = malloc(5);
	// ptr2 = malloc(1000);
	// ptr3 = malloc(2000);

	// free(ptr);
	// free(ptr2);
	// free(ptr3);

	return (0);
}
