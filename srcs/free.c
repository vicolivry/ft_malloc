/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vico <vico@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 10:53:09 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 11:16:00 by vico        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

static void	free_data_large(t_large_data *large, void *ptr)
{
	t_large_data	*prev;

	prev = NULL;
	ft_bzero(ptr, large->size);
	if (g_mapping.large == large && large->next == NULL)
		g_mapping.large = NULL;
	else if (g_mapping.large == large && large->next != NULL)
		g_mapping.large = large->next;
	else
	{
		prev = g_mapping.large;
		while (prev->next && prev->next != large)
			prev = prev->next;
		prev->next = large->next;
	}
	munmap(large->addr, large_zone_size(large->size));
	munmap(large, sizeof(t_large_data));
	ptr = NULL;
}

static int	free_large(void *ptr)
{
	t_large_data	*large;

	large = g_mapping.large;
	if (large == NULL)
		return (0);
	while (large != NULL)
	{
		if (large->addr == ptr)
		{
			free_data_large(large, ptr);
			return (1);
		}
		large = large->next;
	}
	return (0);
}

void		free(void *ptr)
{
	if (ptr == NULL || ptr == 0)
		return ;
	if (is_in_tiny(ptr))
	{
		ft_print("TINY FREED PTR: ");
		put_ui_to_hex((uintmax_t)ptr);
		ft_print("\n");
		free_tiny(ptr);
		return ;
	}
	else if (is_in_small(ptr))
	{	
		ft_print("SMALL FREED PTR: ");
		put_ui_to_hex((uintmax_t)ptr);
		ft_print("\n");
		free_small(ptr);
		return ;
	}
	else if (is_in_large(ptr))
	{		
		ft_print("LARGE FREED PTR: ");
		put_ui_to_hex((uintmax_t)ptr);
		ft_print("\n");
		free_large(ptr);
		ft_print("LARGE FREED\n");
		return ;
	}
	ft_print("FREED PTR: ");
	put_ui_to_hex((uintmax_t)ptr);
	ft_print("\n");
	ft_print("ANORMAL WAY OUT OF FREE\n");
}
