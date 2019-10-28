/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   malloc_tiny.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vico <vico@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 11:15:36 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 14:00:24 by vico        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

static void	*add_zone_tiny(void)
{
	g_mapping.tiny->next = mmap(MMAP_ARGS(PAGESIZE));
	if (g_mapping.tiny->next == MAP_FAILED)
		return (NULL);
	g_mapping.tiny->next->prev = g_mapping.tiny;
	g_mapping.tiny = g_mapping.tiny->next;
	g_mapping.tiny->addr = (void*)mmap(MMAP_ARGS(TINY_SIZE_AREA));
	if (g_mapping.tiny->addr == MAP_FAILED)
		return (NULL);
	g_mapping.tiny->next = NULL;
	g_mapping.tiny->size = TINY_SIZE_AREA - sizeof(t_tiny_data);
	ft_bzero(g_mapping.tiny->data_tab[0], TINY_MAX);
	ft_bzero(g_mapping.tiny->data_tab[1], TINY_MAX);
	return (g_mapping.tiny->addr);
}

static void			*init_zone_tiny(void)
{
	g_mapping.tiny = mmap(MMAP_ARGS(PAGESIZE));
	if (g_mapping.tiny == MAP_FAILED)
		return (NULL);
	g_mapping.tiny->addr = (void*)mmap(MMAP_ARGS(TINY_SIZE_AREA));
	if (g_mapping.tiny->addr == MAP_FAILED)
		return (NULL);
	g_mapping.tiny->next = NULL;
	g_mapping.tiny->prev = NULL;
	g_mapping.tiny->size = TINY_SIZE_AREA - sizeof(t_tiny_data);
	ft_bzero(g_mapping.tiny->data_tab[0], TINY_MAX);
	ft_bzero(g_mapping.tiny->data_tab[1], TINY_MAX);
	return (g_mapping.tiny->addr);
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
	ft_print("TINY NEW PTR: ");
	put_ui_to_hex((uintmax_t)res);
	ft_print("\n");
	return (res);
}
