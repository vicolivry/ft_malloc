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
	size_t size = 5;
	ft_malloc(size);

	void *ptr1 = malloc(5);
	void *ptr2 = malloc(17);
	void *ptr3 = malloc(5);

	ft_printf("1st : %d\n", ptr2 - ptr1);
	ft_printf("2nd : %d\n", ptr3 - ptr2);
	return (0);
}
