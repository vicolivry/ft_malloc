#include "../includes/ft_malloc.h"

static void	*realloc_data_small(t_small_data *small, int i, void *ptr, size_t size)
{
	void*	new_ptr;

	new_ptr = NULL;
	if (size > TINY_ALLOC_SIZE && size <= SMALL_ALLOC_SIZE)
	{
		small->data_tab[1][i] = size;
		return(ptr);
	}
	else
	{
		new_ptr = ft_malloc(size);
		ft_memcpy(new_ptr, ptr, size);
		ft_free(ptr);
		return (new_ptr);
	}
}

void		*realloc_small(void *ptr, size_t size)
{
	t_small_data	*small;
	int			i;

	small = g_mapping.small;
	while (small != NULL)
	{
		i = 0;
		while (i < SMALL_MAX)
		{
			if (small->addr + (i * SMALL_ALLOC_SIZE) == ptr)
				return(realloc_data_small(small, i, ptr, size));

			i++;
		}
		small = small->next;
	}
	return (NULL);
}