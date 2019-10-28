/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   realloc_tiny.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vico <vico@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 11:15:57 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 11:16:00 by vico        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

static void	*realloc_data_tiny(t_tiny_data *tiny, int i, void *ptr, size_t size)
{
	void	*new_ptr;

	new_ptr = NULL;
	if (size <= TINY_ALLOC_SIZE)
	{
		tiny->data_tab[1][i] = size;
		return (ptr);
	}
	else
	{
		new_ptr = malloc(size);
		ft_memcpy(new_ptr, ptr, size);
		free(ptr);
		return (new_ptr);
	}
}

void		*realloc_tiny(void *ptr, size_t size)
{
	t_tiny_data	*tiny;
	int			i;

	tiny = g_mapping.tiny;
	while (tiny != NULL)
	{
		i = 0;
		while (i < TINY_MAX)
		{
			if (tiny->addr + (i * TINY_ALLOC_SIZE) == ptr)
				return (realloc_data_tiny(tiny, i, ptr, size));
			i++;
		}
		tiny = tiny->next;
	}
	return (NULL);
}
