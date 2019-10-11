/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/12 11:47:46 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 11:47:48 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

void print(char *s)
{
  write(1, s, strlen(s));
}

void	tests()
{
	char	*str;
	char	*str2;

	str = NULL;
	str2 = NULL;

	str = (char*)ft_malloc(5618);
	// printf("Ft malloc &str = %p\n\n", &str);
	// int i = 0;
	// str = ft_malloc(47);

	strcpy(str, "HELLO\n");

	// while (i++ < 512)
	// {
	// 	ft_malloc(5);
	// }
	// 	ft_malloc(987);

	// // str2 = malloc(7);
	// printf("ft_malloc return: %p\n", str = ft_malloc(7));
	// printf("Malloc return: %p\n", str2 = malloc(7));


	// strcpy(str, "HELLO");
	// strcpy(str2, "HELLO");
	// // print(str);
	// printf("Ft malloc *str = %c\n", *str);
	// printf("Ft malloc str = %s\n", str);
	// printf("Ft malloc &str = %p\n\n", &str);
	// printf("Real malloc *str = %c\n", *str2);
	// printf("Real malloc str = %s\n", str2);
	// printf("Real malloc &str = %p\n\n", &str2);

	// ft_malloc(5);
	// ft_malloc(5);
	// ft_malloc(5);
	// printf("ft_malloc return: %p\n", str = ft_malloc(7));
	// ft_free(str);
	print(str);
	// ft_putendl("HERE");
	show_alloc_mem();

}

int	main(void)
{
	tests();
	return (0);
}