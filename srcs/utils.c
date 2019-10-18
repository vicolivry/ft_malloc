#include "../includes/ft_malloc.h"

int		zone_is_full(t_page_data *zone, size_t size_max)
{
	size_t  i;

	i = 0;
	while (i < size_max)
	{
		if (zone->data_tab[0][i] == 0)
			return (0);
		i++;
	}
	return (1);
}


int		zone_is_empty(t_page_data *zone, size_t size_max)
{
	size_t i;

	i = 0;
	while (i < size_max)
	{
		if (zone->data_tab[0][i] != 0)
			return (0);
		i++;
	}
	return (1);
}

int		is_in_tiny(void *ptr)
{
	t_page_data	*tiny;
	int			i;

	tiny = g_mapping.tiny;
	if (tiny == NULL)
		return (0);
	while (tiny != NULL)
	{
		i = 0;
		while (i < TINY_MAX)
		{
			if (tiny->addr + (i * TINY_ALLOC_SIZE) == ptr)
				return (1);
			i++;
		}
		tiny = tiny->next;
	}
	return (0);
}

int		is_in_small(void *ptr)
{
	t_page_data	*small;
	int			i;

	small = g_mapping.small;
	if (small == NULL)
		return (0);
	while (small != NULL)
	{
		i = 0;
		while (i < SMALL_MAX)
		{
			if (small->addr + (i * SMALL_ALLOC_SIZE) == ptr)
				return (1);
			i++;
		}
		small = small->next;
	}
	return (0);
}

size_t	large_zone_size(size_t size)
{
	if (size % PAGESIZE == 0)
		return (size);
	else
		return ((size / PAGESIZE + 1) * PAGESIZE);
}
