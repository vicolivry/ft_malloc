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

int		show_alloc_mem_tiny(void)
{
	void		*addr;
	int			i;
	t_page_data	*tiny;
	int			res;

	res = 0;
	tiny = g_mapping.tiny;
	addr = NULL;
	while (tiny != NULL)
	{
		ft_print("TINY: ");
		put_ui_to_hex((unsigned long)tiny->addr); 
		ft_print("\n");
		i = 0;
		addr = tiny->addr;
		while (i < TINY_MAX)
		{
			if (tiny->data_tab[0][i] != 0)
				res += display_alloc_mem(tiny, i);
			i++;
		}
		tiny = tiny->next;
	}
	return (res);
}

int		show_alloc_mem_small(void)
{
	void	*addr;
	int		i;
	t_page_data	*small;
	int			res;

	res = 0;
	small = g_mapping.small;
	addr = NULL;
	while (small != NULL)
	{
		ft_print("SMALL: ");
		put_ui_to_hex((unsigned long)small->addr); 
		ft_print("\n");
		i = 0;
		addr = small->addr;
		while (i < SMALL_MAX)
		{
			if (small->data_tab[0][i] != 0)
				res += display_alloc_mem(small, i);
			i++;
		}
		small = small->next;
	}
	return (res);
}

int		show_alloc_mem_large(void)
{
	void		*addr;
	int			i;
	t_page_data	*large;
	int			res;

	res = 0;
	large = g_mapping.large;
	addr = NULL;
	i = 0;
	while (large != NULL)
	{
		ft_print("LARGE: ");
		put_ui_to_hex((unsigned long)large->addr); 
		ft_print("\n");
		addr = large->addr;
		res += display_alloc_mem(large, i);
		large = large->next;
	}
	return (res);
}

void	show_alloc_mem(void)
{
	int		res;
	res = 0;

	if (g_mapping.tiny != NULL)
		res += show_alloc_mem_tiny();
	if (g_mapping.small != NULL)
		res += show_alloc_mem_small();
	if (g_mapping.large != NULL)
		res += show_alloc_mem_large();
	if (res)
	{
		ft_print("Total : ");
		ft_putnbr(res);
		ft_print("\n");
	}
}