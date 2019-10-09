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

int		show_alloc_mem_tiny(int res)
{
	void	*addr;
	int		i;

	addr = &g_mapping.tiny;
	i = 0;
	while (g_mapping.tiny->next != NULL)
	{
		write(1, "TINY: ", 6);
		ft_printf("%p\n", &g_mapping.tiny->next);
		i = 0;
		while (i < TINY_MAX)
		{
			if (g_mapping.tiny->data_tab[0][i] != 0)
			{
				ft_printf("%p - %p : %d octets\n",  addr + (i * TINY_ALLOC_SIZE), addr + (i * TINY_ALLOC_SIZE) +\
				g_mapping.tiny->data_tab[1][i], g_mapping.tiny->data_tab[1][i]);
				res += g_mapping.tiny->data_tab[1][i];
			}
			i++;
		}
		g_mapping.tiny = g_mapping.tiny->next;
	}
	while (g_mapping.tiny->prev != NULL)
			g_mapping.tiny = g_mapping.tiny->prev;
		return (res);
}

void	show_alloc_mem()
{
	int		res;

	res = 0;

	if (g_mapping.tiny != NULL)
		res += show_alloc_mem_tiny(res);
	if (res)
		ft_printf("Total : %d\n", res);
}