/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 11:15:11 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 11:15:12 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

static void		*realloc_data_large(t_large_data *large, void *ptr, size_t size)
{
	void	*new_ptr;

	new_ptr = NULL;
	if (size > SMALL_ALLOC_SIZE && size > large_zone_size(large->size))
	{
		large->size = size;
		return (ptr);
	}
	else
	{
		new_ptr = ft_malloc(size);
		ft_memcpy(new_ptr, ptr, size);
		ft_free(ptr);
		return (new_ptr);
	}
}

static void		*realloc_large(void *ptr, size_t size)
{
	t_large_data	*large;

	large = g_mapping.large;
	while (large != NULL)
	{
		if (large->addr == ptr)
			return (realloc_data_large(large, ptr, size));
		large = large->next;
	}
	return (NULL);
}

static int		is_in_large(void *ptr)
{
	t_large_data	*large;

	large = g_mapping.large;
	if (large == NULL)
		return (0);
	while (large != NULL)
	{
		if (large->addr == ptr)
			return (1);
		large = large->next;
	}
	return (0);
}

void			*ft_realloc(void *ptr, size_t size)
{
	if (size <= 0)
		return (NULL);
	if (is_in_tiny(ptr))
		return (realloc_tiny(ptr, size));
	else if (is_in_small(ptr))
		return (realloc_small(ptr, size));
	else if (is_in_large(ptr))
		return (realloc_large(ptr, size));
	return (NULL);
}
