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

void	init_page_tiny()
{
	int i;
	i = 0;
	t_page_data	*new_page;

	new_page = mmap(MMAP_ARGS(TINY_SIZE_AREA));
	if (new_page == NULL)
		return ;
	new_page->type = TINY;
	new_page->next = NULL;
	new_page->prev = NULL;
	new_page->size = TINY_SIZE_AREA - sizeof(t_page_data);
	new_page->data_tab = (int**)mmap(MMAP_ARGS(2 * sizeof(int*)));
	new_page->data_tab[0] = (int*)mmap(MMAP_ARGS(TINY_MAX * sizeof(int)));
	new_page->data_tab[1] = (int*)mmap(MMAP_ARGS(TINY_MAX * sizeof(int)));
	while (i < TINY_MAX)
	{
		new_page->data_tab[0][i] = 0;
		new_page->data_tab[1][i] = 0;
		i++;
	}
	g_mapping.tiny = new_page;
	// TODO if null create, else g_mapping.tiny == g_mapping.tiny->next
	ft_printf("ZONE Adress: %p\n", &g_mapping.tiny);
}

void	*malloc_tiny(size_t size)
{
	void	*res;
	int		i;

	i = 0;
	if (g_mapping.tiny == NULL)
		init_page_tiny();
	while (g_mapping.tiny->data_tab[0][i])
		i++;
	ft_putstr("HERE\n");
	g_mapping.tiny->data_tab[0][i] = 1;
	g_mapping.tiny->data_tab[1][i] = size;
	res = (void*)(g_mapping.tiny) + (i * TINY_ALLOC_SIZE);
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
    return (0);
} 

