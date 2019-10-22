/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vico <vico@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 10:53:09 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 17:50:12 by vico        ###    #+. /#+    ###.fr     */
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
	if (free_tiny(ptr))
		return ;
	else if (free_small(ptr))
		return ;
	else
		free_large(ptr);
}
