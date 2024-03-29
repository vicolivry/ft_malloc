/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_malloc.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vico <vico@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/12 15:25:46 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 15:25:10 by vico        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"
#include <stdio.h>

t_mapping	g_mapping = {NULL, NULL, NULL};

static t_large_data	*add_zone_large(size_t size, size_t zone_size)
{
	g_mapping.large->next = mmap(MMAP_ARGS(zone_size + sizeof(t_large_data)));
	if (g_mapping.large->next == MAP_FAILED)
		return (NULL);
	g_mapping.large->next->prev = g_mapping.large;
	g_mapping.large = g_mapping.large->next;
	g_mapping.large->addr = mmap(MMAP_ARGS(zone_size));
	g_mapping.large->next = NULL;
	g_mapping.large->size = size;
	return (g_mapping.large);
}

static void			*init_zone_large(size_t size, size_t zone_size)
{
	g_mapping.large = mmap(MMAP_ARGS(sizeof(t_large_data)));
	if (g_mapping.large == MAP_FAILED)
		return (NULL);
	g_mapping.large->addr = mmap(MMAP_ARGS(zone_size));
	g_mapping.large->next = NULL;
	g_mapping.large->prev = NULL;
	g_mapping.large->size = size;
	return (g_mapping.large);
}

static void			*malloc_large(size_t size, size_t zone_size)
{
	void			*res;

	if (g_mapping.large == NULL)
	{
		if (init_zone_large(size, zone_size) == NULL)
			return (NULL);
	}
	else
	{
		while (g_mapping.large->next != NULL)
			g_mapping.large = g_mapping.large->next;
		g_mapping.large = add_zone_large(size, zone_size);
	}
	res = g_mapping.large->addr;
	while (g_mapping.large->prev)
		g_mapping.large = g_mapping.large->prev;
	return (res);
}

void				*malloc(size_t size)
{
	if (size <= 0)
		return (NULL);
	if (size <= TINY_ALLOC_SIZE)
		return (malloc_tiny(size));
	else if (size <= SMALL_ALLOC_SIZE)
		return (malloc_small(size));
	else
		return (malloc_large(size, large_zone_size(size)));
	return (NULL);
}
