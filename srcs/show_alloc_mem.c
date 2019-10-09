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
	t_page_data	*tiny;

	tiny = g_mapping.tiny;
	addr = NULL;
	i = 0;
	while (tiny != NULL)
	{
		write(1, "TINY: ", 6);
		ft_printf("%p\n", tiny->addr);
		i = 0;
		addr = tiny->addr;
		while (i < TINY_MAX)
		{
			if (tiny->data_tab[0][i] != 0)
			{
				ft_printf("%p - %p : %d octets\n",  addr + (i * TINY_ALLOC_SIZE), addr + (i * TINY_ALLOC_SIZE) +\
				tiny->data_tab[1][i], tiny->data_tab[1][i]);
				res += tiny->data_tab[1][i];
			}
			i++;
		}
		tiny = tiny->next;
	}
	return (res);
}

int		show_alloc_mem_small(int res)
{
	void	*addr;
	int		i;
	t_page_data	*small;

	small = g_mapping.small;
	addr = NULL;
	i = 0;
	while (small != NULL)
	{
		write(1, "SMALL: ", 6);
		ft_printf("%p\n", small->addr);
		i = 0;
		addr = small->addr;
		while (i < SMALL_MAX)
		{
			if (small->data_tab[0][i] != 0)
			{
				ft_printf("%p - %p : %d octets\n",  addr + (i * SMALL_ALLOC_SIZE), addr + (i * SMALL_ALLOC_SIZE) +\
				small->data_tab[1][i], small->data_tab[1][i]);
				res += small->data_tab[1][i];
			}
			i++;
		}
		small = small->next;
	}
	return (res);
}

int		show_alloc_mem_large(int res)
{
	void	*addr;
	int		i;
	t_page_data	*large;

	large = g_mapping.large;
	addr = NULL;
	i = 0;
	while (large != NULL)
	{
		write(1, "LARGE: ", 6);
		ft_printf("%p\n", large->addr);
		addr = large->addr;
		ft_printf("%p - %p : %d octets\n", addr, addr + large->size, large->size);
		res += large->size;
		large = large->next;
	}
	return (res);
}

void	show_alloc_mem()
{
	int		res;
	res = 0;

	if (g_mapping.tiny != NULL)
		res += show_alloc_mem_tiny(res);
	if (g_mapping.small != NULL)
		res += show_alloc_mem_small(res);
	if (g_mapping.large != NULL)
		res += show_alloc_mem_large(res);
	if (res)
		ft_printf("Total : %d\n", res);
}