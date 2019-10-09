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

int	main(void)
{
	char	*str;

	str = NULL;
	int i = 0;
	while (i++ < 150)
	{
		ft_malloc(5);
		ft_malloc(42);
		ft_malloc(6987);

	}
	str = (char*)ft_malloc(7);
	show_alloc_mem();
	str[0] = 'H';
	str[1] = 'e';
	str[2] = 'l';
	str[3] = 'l';
	str[4] = 'o';
	str[5] = '\n';
	str[6] = '\0';
	ft_putstr(str);
	return (0);
}