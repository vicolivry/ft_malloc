/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   malloc_tiny.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vico <vico@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 11:15:36 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 11:13:45 by vico        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

static t_tiny_data	*add_zone_tiny(void)
{
	g_mapping.tiny->next = mmap(MMAP_ARGS(sizeof(t_tiny_data)));
	if (g_mapping.tiny->next == MAP_FAILED)
		return (NULL);
	g_mapping.tiny->next->prev = g_mapping.tiny;
	g_mapping.tiny = g_mapping.tiny->next;
	g_mapping.tiny->addr = mmap(MMAP_ARGS(TINY_SIZE_AREA));
	g_mapping.tiny->next = NULL;
	g_mapping.tiny->size = TINY_SIZE_AREA - sizeof(t_tiny_data);
	ft_bzero(g_mapping.tiny->data_tab[0], TINY_MAX);
	ft_bzero(g_mapping.tiny->data_tab[1], TINY_MAX);
	return (g_mapping.tiny);
}

static void			*init_zone_tiny(void)
{
	g_mapping.tiny = mmap(MMAP_ARGS(sizeof(t_tiny_data)));
	if (g_mapping.tiny == MAP_FAILED)
		return (NULL);
	g_mapping.tiny->addr = mmap(MMAP_ARGS(TINY_SIZE_AREA));
	g_mapping.tiny->next = NULL;
	g_mapping.tiny->prev = NULL;
	g_mapping.tiny->size = TINY_SIZE_AREA - sizeof(t_tiny_data);
	ft_bzero(g_mapping.tiny->data_tab[0], TINY_MAX);
	ft_bzero(g_mapping.tiny->data_tab[1], TINY_MAX);
	return (g_mapping.tiny);
}

void				*malloc_tiny(size_t size)
{
	void		*res;
	int			i;

	i = 0;
	if (g_mapping.tiny == NULL)
	{
		if (init_zone_tiny() == NULL)
			return (NULL);
	}
	else
	{
		while (tiny_is_full(g_mapping.tiny) && g_mapping.tiny->next != NULL)
			g_mapping.tiny = g_mapping.tiny->next;
		if (tiny_is_full(g_mapping.tiny) && g_mapping.tiny->next == NULL)
			g_mapping.tiny = add_zone_tiny();
	}
	while (g_mapping.tiny->data_tab[0][i])
		i++;
	g_mapping.tiny->data_tab[0][i] = 1;
	g_mapping.tiny->data_tab[1][i] = size;
	res = g_mapping.tiny->addr + (i * TINY_ALLOC_SIZE);
	while (g_mapping.tiny->prev)
		g_mapping.tiny = g_mapping.tiny->prev;
	return (res);
}
