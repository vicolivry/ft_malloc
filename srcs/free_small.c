#include "../includes/ft_malloc.h"

static void	free_data_small(t_page_data *small, int i, void *ptr)
{
	t_page_data  *prev;
    prev = NULL;

	ft_bzero(ptr, small->data_tab[0][i]);
	small->data_tab[1][i] = 0;
	small->data_tab[0][i] = 0;
    if (!zone_is_empty(small, SMALL_MAX))
        return;
    if (g_mapping.small == small && small->next == NULL)
		g_mapping.small = NULL;
    else if (g_mapping.small == small && small->next != NULL)
        g_mapping.small = small->next;
    else
    {
        prev = g_mapping.small;
        while (prev->next && prev->next != small)
            prev = prev->next;
        prev->next = small->next;
    }
	munmap(small->addr, SMALL_SIZE_AREA);
	munmap(small, sizeof(t_page_data));
}

int			free_small(void *ptr)
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
			{
				free_data_small(small, i, ptr);
				return (1);
			}
			i++;
		}
		small = small->next;
	}
	return (0);
}
