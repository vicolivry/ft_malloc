#include "../includes/ft_malloc.h"

size_t	large_zone_size(size_t size)
{
	if (size % PAGESIZE == 0)
		return (size);
	else
		return ((size / PAGESIZE + 1) * PAGESIZE);
}
