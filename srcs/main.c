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
	ft_printf("Pagesize = %d\n", PAGESIZE);
	ft_printf("Mmap return = %xld\n", mmap(MMAP_ARGS(2)));
	return (0);
}
