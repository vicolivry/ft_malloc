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
#include <errno.h>

t_mapping	*g_mapping = NULL;



void	init_map(size_t size)
{
	t_page_info		*page;
	page = NULL;

	g_mapping = mmap(MMAP_ARGS(size));
	g_mapping->page = page;
	g_mapping->next = NULL;
}

void	init_page(size_t size, t_page_info *page)
{
	t_page_alloc	*alloc;

	alloc = NULL;
	page = mmap(MMAP_ARGS(TINY_SIZE_AREA));
	page->type = TINY;
	page->next = NULL;
	page->addr = page;
	// DEBUG
	ft_printf("PAGE Adress:%x\n", page->addr);
	ft_printf("Type : %d\n", page->type);
	// END DEBUG
	page->alloc->size = size;
	ft_printf("HERE\n");
	page->alloc->addr = page->addr + 1;
	page->alloc->next = NULL;
}


void	*malloc_tiny(size_t size)
{
	if (g_mapping == NULL)
		init_map(size);
	ft_printf("mapping: %x\n", g_mapping);

	if (g_mapping->page == NULL)
		init_page(size, g_mapping->page);
	return(g_mapping->page->alloc->addr);
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