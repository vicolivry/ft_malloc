#include "../includes/ft_malloc.h"

int			zone_is_full(t_page_data *zone, size_t size_max)
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


int			zone_is_empty(t_page_data *zone, size_t size_max)
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

size_t	large_zone_size(size_t size)
{
	if (size % PAGESIZE == 0)
		return (size);
	else
		return ((size / PAGESIZE + 1) * PAGESIZE);
}
