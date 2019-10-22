#include "includes/ft_malloc.h"

int main(void)
{
	char *str;
	char	*str2;
	char	*str3;

	str = (char*)malloc(6);
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = 'd';
	str[4] = '\n';
	str[5] = '\0';
	str2 = (char*)malloc(10000000000000);
	str3 = (char*)malloc(10000000000000);
	str2[1] = '\n';
	str2[3] = '\0';

	ft_print(str);
	// free(str);
	// show_alloc_mem();
	// ft_print(str2);
	return (0);
}