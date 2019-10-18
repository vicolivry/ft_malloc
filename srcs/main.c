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

void	tests()
{
	char	*str;
	char	*str2;

	str = NULL;
	str2 = NULL;

	// str = (char*)malloc(561);
	// printf("Ft malloc &str = %p\n\n", &str);
	// int i = 0;
	// str = ft_malloc(47);

	// ft_printf("str ptr: %p\n", str = (char*)ft_malloc(2020));
	// str[0] = 'A';
	// str[1] = 'A';
	// str[2] = 'A';
	// str[3] = 'A';
	// str[4] = 'A';
	// str[5] = 'A';
	// str[6] = 'A';
	// str[7] = 'A';
	// str[8] = 'A';
	// str[9] = 'A';
	// str[10] = 'A';
	// str[11] = 'A';
	// str[12] = 'A';
	// str[13] = 'A';
	// str[14] = 'A';
	// str[15] = 'A';
	// str[16] = 'A';
	// str[17] = 'A';
	// str[18] = 'A';
	// str[19] = '\n';

	// show_alloc_mem();
	// print(str);
	// ft_free(str);
	// ft_malloc(5);
	ft_malloc(25);
	ft_malloc(25);
	// ft_malloc(35);
	ft_malloc(5000);
	// ft_malloc(5000);
	show_alloc_mem();
	// print(str);

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
	// print(str);
	// ft_putendl("HERE");

}

int	main(void)
{
	tests();
	return (0);
}