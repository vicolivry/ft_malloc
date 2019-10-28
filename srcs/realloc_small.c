/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   realloc_small.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vico <vico@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 11:15:48 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 11:16:00 by vico        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

static void	*realloc_data_small(t_small_data *small, int i, void *ptr, size_t s)
{
	void	*new_ptr;

	new_ptr = NULL;
	if (s > TINY_ALLOC_SIZE && s <= SMALL_ALLOC_SIZE)
	{
		small->data_tab[1][i] = s;
		return (ptr);
	}
	else
	{
		new_ptr = malloc(s);
		ft_memcpy(new_ptr, ptr, s);
		free(ptr);
		return (new_ptr);
	}
}

void		*realloc_small(void *ptr, size_t size)
{
	t_small_data	*small;
	int				i;

	small = g_mapping.small;
	while (small != NULL)
	{
		i = 0;
		while (i < SMALL_MAX)
		{
			if (small->addr + (i * SMALL_ALLOC_SIZE) == ptr)
				return (realloc_data_small(small, i, ptr, size));
			i++;
		}
		small = small->next;
	}
	return (NULL);
}
