/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_tiny.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vico <vico@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 11:14:51 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 16:28:55 by vico        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

static void	free_data_tiny(t_tiny_data *tiny, int i, void *ptr)
{
	t_tiny_data	*prev;

	prev = NULL;
	ft_bzero(ptr, tiny->data_tab[0][i]);
	tiny->data_tab[1][i] = 0;
	tiny->data_tab[0][i] = 0;
	ptr = NULL;
	if (tiny_is_empty(tiny))
		return ;
	if (g_mapping.tiny == tiny && tiny->next == NULL)
		g_mapping.tiny = NULL;
	else if (g_mapping.tiny == tiny && tiny->next != NULL)
		g_mapping.tiny = tiny->next;
	else
	{
		prev = g_mapping.tiny;
		while (prev->next && prev->next != tiny)
			prev = prev->next;
		prev->next = tiny->next;
	}
	munmap(tiny->addr, TINY_SIZE_AREA);
	munmap(tiny, sizeof(t_tiny_data));
}

int			free_tiny(void *ptr)
{
	t_tiny_data	*tiny;
	int			i;

	tiny = g_mapping.tiny;
	if (tiny == NULL)
		return (0);
	while (tiny != NULL)
	{
		i = 0;
		while (i < TINY_MAX)
		{
			if (tiny->addr + (i * TINY_ALLOC_SIZE) == ptr)
			{
				free_data_tiny(tiny, i, ptr);
				return (1);
			}
			i++;
		}
		tiny = tiny->next;
	}
	return (0);
}
