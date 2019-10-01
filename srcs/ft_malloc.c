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

void	print_data(t_page_data *p)
{
	ft_printf("PAGE Adress: %p\n", p);
	ft_printf("Type : %d\n", p->type);
	ft_printf("Alloc size : %d\n", p->data_tab[0][1]);
	ft_printf("Size : %d\n\n", p->size);
}

void	*init_page_tiny(t_page_data **new_page)
{
	int i;

	i = 0;

	*new_page = mmap(MMAP_ARGS(TINY_SIZE_AREA));
	if (*new_page == NULL)
		return (NULL);
	(*new_page)->type = TINY;
	(*new_page)->next = NULL;
	(*new_page)->prev = NULL;
	(*new_page)->size = TINY_SIZE_AREA - sizeof(t_page_data);
	(*new_page)->data_tab = (int**)mmap(MMAP_ARGS(2 * sizeof(int*)));
	while (i < TINY_MAX)
	{
		(*new_page)->data_tab[i] = (int*)mmap(MMAP_ARGS(TINY_MAX * sizeof(int)));
		(*new_page)->data_tab[i][0] = 0;
		(*new_page)->data_tab[i][1] = 7;
		i++;
	}
	return (new_page);
}

// void	*init_page_tiny(t_page_data **new_page)
// {
// 	t_page_data	*header;

// 	header = NULL;
// 	*new_page = mmap(MMAP_ARGS(TINY_SIZE_AREA));
// 	if (*new_page == NULL)
// 		return (NULL);
// 	(*new_page)->type = TINY;
// 	(*new_page)->next = NULL;
// 	(*new_page)->prev = NULL;
// 	(*new_page)->size = TINY_SIZE_AREA - sizeof(t_page_data);
// 	(*new_page)->is_free = FALSE;
// 	(*new_page)->alloc_size = 0;

// 	header = *new_page + 1;
// 	header->next = NULL;
// 	header->prev = NULL;
// 	header->size = (*new_page)->size - sizeof(t_page_data);
// 	header->is_free = TRUE;
// 	header->alloc_size = 0;
// 	header->type = TINY;
// 	return (header);
// }


void	*data_alloc_tiny(size_t size, t_page_data **tiny_page)
{
	int		i;
	void	*res;

	i = 0;
	while ((*tiny_page)->data_tab[i][0])
		i++;
	(*tiny_page)->data_tab[i][0] = 1;
	(*tiny_page)->data_tab[i][1] = size;
	res = (void*)tiny_page + i * TINY_ALLOC_SIZE;

	return (res);
}



// void	*data_alloc_tiny(size_t size, t_page_data **tiny_page)
// {


// 	new_empty = NULL;
// 	new_alloc = *tiny_page + 1;
// 	while (new_alloc->is_free == FALSE)
// 		new_alloc = new_alloc->next;
// 	if (new_alloc == NULL)
// 		return (NULL);
// 	// TODO : IF ENOUGH SIZE IN ZONE OTHERWISE CREATE NEW ZONE
// 	new_alloc->type = TINY;
// 	new_alloc->next = new_alloc + TINY_ALLOC_SIZE;
// 	new_alloc->prev = new_alloc - TINY_ALLOC_SIZE;
// 	new_alloc->is_free = FALSE;
// 	new_alloc->alloc_size = size;

// 	new_empty = new_alloc + TINY_ALLOC_SIZE;
// 	new_empty->next = NULL;
// 	new_empty->prev = NULL;
// 	new_empty->size = new_alloc->size - TINY_ALLOC_SIZE;
// 	new_empty->is_free = TRUE;
// 	new_empty->alloc_size = 0;
// 	new_empty->type = TINY;
// 	return (new_alloc);
// }

void	*malloc_tiny(size_t size, t_mapping *g_mapping)
{
	void	*res;
	// t_page_data	*new_alloc;


	if (g_mapping->tiny == NULL)
		init_page_tiny(&g_mapping->tiny);
	res = data_alloc_tiny(size, &g_mapping->tiny);

	print_data(g_mapping->tiny);
	return (res);
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