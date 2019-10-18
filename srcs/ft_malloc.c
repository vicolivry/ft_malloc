/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_malloc.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/12 15:25:46 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 15:25:47 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

t_mapping	g_mapping = {NULL, NULL, NULL};

static t_page_data	*add_zone_large(size_t size, size_t zone_size)
{
	g_mapping.large->next = mmap(MMAP_ARGS(zone_size + sizeof(t_page_data)));
	if (g_mapping.large->next == NULL)
		return (NULL);
	g_mapping.large->next->prev = g_mapping.large;
	g_mapping.large = g_mapping.large->next;
	g_mapping.large->addr = &g_mapping.large->next;	
	g_mapping.large->type = LARGE;
	g_mapping.large->next = NULL;
	g_mapping.large->size = size;
	g_mapping.large->data_tab = NULL;
	return (g_mapping.large);
}

static void			init_zone_large(size_t size,size_t zone_size)
{
	g_mapping.large = mmap(MMAP_ARGS(sizeof(t_page_data)));
	if (g_mapping.large == NULL)
		return ;
	g_mapping.large->addr = mmap(MMAP_ARGS(zone_size));
	g_mapping.large->type = LARGE;
	g_mapping.large->next = NULL;
	g_mapping.large->prev = NULL;
	g_mapping.large->size =  size;
	g_mapping.large->data_tab = NULL;
}

void	        	*malloc_large(size_t size, size_t zone_size)
{
	void		*res;
	int			i;

	i = 0;
	if (g_mapping.large == NULL)
		init_zone_large(size, zone_size);
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

void				*ft_malloc(size_t size)
{
	if (size <= 0)
		return (NULL);
	if (size <= TINY_ALLOC_SIZE)
		return(malloc_tiny(size));
	else if (size  <= SMALL_ALLOC_SIZE)
		return(malloc_small(size));
	else
		return(malloc_large(size, large_zone_size(size)));
    return (NULL);
} 

