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

t_mapping	g_mapping = {NULL, NULL, NULL};

void	print_data(t_page_data *p)
{
	ft_printf("PAGE Adress: %d\n", p);
	ft_printf("Type : %d\n", p->type);
	ft_printf("Size : %d\n", p->size);
}

void	*init_page(void)
{
	t_page_data	*new_page;
	t_page_data	*header;

	new_page = mmap(MMAP_ARGS(TINY_SIZE_AREA));
	if (new_page == NULL)
		return (NULL);
	new_page->type = TINY;
	new_page->next = NULL;
	new_page->prev = NULL;
	new_page->size = TINY_SIZE_AREA - sizeof(t_page_data);
	new_page->is_free = FALSE;

	print_data(new_page);

	header = new_page + 1;
	header->next = NULL;
	header->prev = NULL;
	header->size = new_page->size - sizeof(t_page_data);
	header->is_free = TRUE;
	header->type = TINY;

	print_data(header);
	return (NULL);
}


void	*malloc_tiny(size_t size, t_mapping *g_mapping)
{
	if (g_mapping->tiny == NULL)
		init_page();
	size = 1;
	return (NULL);
}


void	*ft_malloc(size_t size)
{
	if (!size)
		return (NULL);

	if (size <= TINY_ALLOC_SIZE)
		return(malloc_tiny(size, &g_mapping));
	// else if (size > TINY_ALLOC_SIZE && size  <= SMALL_ALLOC_SIZE)
	// 	malloc_small(size);
	// else
	// 	malloc_large(size);
    return (0);
}