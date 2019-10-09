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

int     zone_is_full_tiny(t_page_data *tiny)
{
    int i;

    i = 0;
    while (i < TINY_MAX)
    {
        if (tiny->data_tab[0][i] == 0)
            return (0);
        i++;
    }
    return (1);
}

t_page_data	*add_zone_tiny()
{
	ft_putstr("ADD ZONE\n");

	g_mapping.tiny->next = mmap(MMAP_ARGS(TINY_SIZE_AREA));
	if (g_mapping.tiny->next == NULL)
		return (NULL);
	g_mapping.tiny->next->type = TINY;
	g_mapping.tiny->next->next = NULL;
	g_mapping.tiny->next->prev = g_mapping.tiny;
	g_mapping.tiny->next->size = TINY_SIZE_AREA - sizeof(t_page_data);
	g_mapping.tiny->next->data_tab = (int**)mmap(MMAP_ARGS(2 * sizeof(int*)));
	g_mapping.tiny->next->data_tab[0] = (int*)mmap(MMAP_ARGS(TINY_MAX * sizeof(int)));
	g_mapping.tiny->next->data_tab[1] = (int*)mmap(MMAP_ARGS(TINY_MAX * sizeof(int)));
	ft_bzero(g_mapping.tiny->next->data_tab[0], TINY_MAX);
	ft_bzero(g_mapping.tiny->next->data_tab[1], TINY_MAX);
	return (g_mapping.tiny->next);
}

void	init_zone_tiny()
{
	g_mapping.tiny = mmap(MMAP_ARGS(TINY_SIZE_AREA));
	if (g_mapping.tiny == NULL)
		return ;
	g_mapping.tiny->type = TINY;
	g_mapping.tiny->next = NULL;
	g_mapping.tiny->prev = NULL;
	g_mapping.tiny->size = TINY_SIZE_AREA - sizeof(t_page_data);
	g_mapping.tiny->data_tab = (int**)mmap(MMAP_ARGS(2 * sizeof(int*)));
	g_mapping.tiny->data_tab[0] = (int*)mmap(MMAP_ARGS(TINY_MAX * sizeof(int)));
	g_mapping.tiny->data_tab[1] = (int*)mmap(MMAP_ARGS(TINY_MAX * sizeof(int)));
	ft_bzero(g_mapping.tiny->data_tab[0], TINY_MAX);
	ft_bzero(g_mapping.tiny->data_tab[1], TINY_MAX);
}

void	*malloc_tiny(size_t size)
{
	void		*res;
	int			i;

	i = 0;
	if (g_mapping.tiny == NULL)
	{
		init_zone_tiny();
			ft_printf("ZONE ADDR: %p\n", &g_mapping.tiny);
	}
	else
	{
		while (zone_is_full_tiny(g_mapping.tiny) && g_mapping.tiny->next != NULL)
			g_mapping.tiny = g_mapping.tiny->next;
		if (zone_is_full_tiny(g_mapping.tiny) && g_mapping.tiny->next == NULL)
		{
			g_mapping.tiny = add_zone_tiny();
			ft_printf("ZONE ADDR: %p\n", &g_mapping.tiny);
		}
	}
	while (g_mapping.tiny->data_tab[0][i])
		i++;
	g_mapping.tiny->data_tab[0][i] = 1;
	g_mapping.tiny->data_tab[1][i] = size;
	res = (void*)(g_mapping.tiny) + (i * TINY_ALLOC_SIZE);
	while (g_mapping.tiny->prev)
		g_mapping.tiny = g_mapping.tiny->prev;
	return (res);
}


void	*ft_malloc(size_t size)
{
	if (!size)
		return (NULL);
	if (size <= TINY_ALLOC_SIZE)
		return(malloc_tiny(size));
	// else if (size > TINY_ALLOC_SIZE && size  <= SMALL_ALLOC_SIZE)
	// 	malloc_small(size);
	// else
	// 	malloc_large(size);
    return (NULL);
} 

