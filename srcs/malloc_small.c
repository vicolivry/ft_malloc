/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   malloc_small.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vico <vico@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 11:15:23 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 15:22:16 by vico        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

static t_small_data	*add_zone_small(void)
{
	g_mapping.small->next = (t_small_data*)mmap(MMAP_ARGS(PAGESIZE));
	if (g_mapping.small->next == MAP_FAILED)
		return (NULL);
	g_mapping.small->next->prev = g_mapping.small;
	g_mapping.small = g_mapping.small->next;
	g_mapping.small->addr = (void*)mmap(MMAP_ARGS(SMALL_SIZE_AREA));
	if (g_mapping.small->addr == MAP_FAILED)
		return (NULL);
	g_mapping.small->next = NULL;
	g_mapping.small->size = SMALL_SIZE_AREA;
	ft_bzero(g_mapping.small->data_tab[0], SMALL_MAX);
	ft_bzero(g_mapping.small->data_tab[1], SMALL_MAX);
	return (g_mapping.small);
}

static void			*init_zone_small(void)
{
	g_mapping.small = (t_small_data*)mmap(MMAP_ARGS(PAGESIZE));
	if (g_mapping.small == MAP_FAILED)
		return (NULL);
	g_mapping.small->addr = (void*)mmap(MMAP_ARGS(SMALL_SIZE_AREA));
	if (g_mapping.small->addr == MAP_FAILED)
		return (NULL);
	g_mapping.small->next = NULL;
	g_mapping.small->prev = NULL;
	g_mapping.small->size = SMALL_SIZE_AREA;
	ft_bzero(g_mapping.small->data_tab[0], SMALL_MAX);
	ft_bzero(g_mapping.small->data_tab[1], SMALL_MAX);
	return (g_mapping.small);
}

void				*malloc_small(size_t size)
{
	void		*res;
	int			i;

	i = 0;
	if (g_mapping.small == NULL)
	{
		if (init_zone_small() == NULL)
			return (NULL);
	}
	else
	{
		while (small_is_full(g_mapping.small) && g_mapping.small->next != NULL)
			g_mapping.small = g_mapping.small->next;
		if (small_is_full(g_mapping.small) && g_mapping.small->next == NULL)
			g_mapping.small = add_zone_small();
	}
	while (g_mapping.small->data_tab[0][i])
		i++;
	g_mapping.small->data_tab[0][i] = 1;
	g_mapping.small->data_tab[1][i] = size;
	res = g_mapping.small->addr + (i * SMALL_ALLOC_SIZE);
	while (g_mapping.small->prev)
		g_mapping.small = g_mapping.small->prev;
	return (res);
}
