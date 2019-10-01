/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   show_alloc_mem.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/01 11:26:59 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/01 11:27:00 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "../includes/ft_malloc.h"

void	show_alloc_mem()
{
	void	*addr;
	int		i;

	i = 0;
	addr = &g_mapping.tiny;
	if (g_mapping.tiny != NULL)
	{
		write(1, "TINY: ", 6);
		ft_printf("%p\n", &g_mapping.tiny);
	}
	while (i < TINY_MAX)
	{
		// ft_putstr("HOP\n");
		if (g_mapping.tiny->data_tab[0][i] != 0)
		{
			ft_printf("%p - %p : %d octets\n",  addr + (i * TINY_ALLOC_SIZE), addr + (i * TINY_ALLOC_SIZE) +\
			g_mapping.tiny->data_tab[1][i], g_mapping.tiny->data_tab[1][i]);
		}
		i++;
	}
}