
#include "../includes/ft_malloc.h"

static int			zone_is_full_small(t_page_data *small)
{
	int i;

	i = 0;
	while (i < SMALL_MAX)
	{
		if (small->data_tab[0][i] == 0)
			return (0);
		i++;
	}
	return (1);
}

static t_page_data	*add_zone_small()
{
	g_mapping.small->next = mmap(MMAP_ARGS(SMALL_SIZE_AREA));
	if (g_mapping.small->next == NULL)
		return (NULL);
	g_mapping.small->next->prev = g_mapping.small;
	g_mapping.small = g_mapping.small->next;
	g_mapping.small->addr = &g_mapping.small->next;	
	g_mapping.small->type = SMALL;
	g_mapping.small->next = NULL;
	g_mapping.small->size = SMALL_SIZE_AREA - sizeof(t_page_data);
	g_mapping.small->data_tab = (int**)mmap(MMAP_ARGS(2 * sizeof(int*)));
	g_mapping.small->data_tab[0] = (int*)mmap(MMAP_ARGS(SMALL_MAX * sizeof(int)));
	g_mapping.small->data_tab[1] = (int*)mmap(MMAP_ARGS(SMALL_MAX * sizeof(int)));
	ft_bzero(g_mapping.small->data_tab[0], SMALL_MAX);
	ft_bzero(g_mapping.small->data_tab[1], SMALL_MAX);
	return (g_mapping.small);
}

static void		init_zone_small()
{
	g_mapping.small = mmap(MMAP_ARGS(SMALL_SIZE_AREA));
	if (g_mapping.small == NULL)
		return ;
	g_mapping.small->addr = &g_mapping.small;
	g_mapping.small->type = SMALL;
	g_mapping.small->next = NULL;
	g_mapping.small->prev = NULL;
	g_mapping.small->size = SMALL_SIZE_AREA - sizeof(t_page_data);
	g_mapping.small->data_tab = (int**)mmap(MMAP_ARGS(2 * sizeof(int*)));
	g_mapping.small->data_tab[0] = (int*)mmap(MMAP_ARGS(SMALL_MAX * sizeof(int)));
	g_mapping.small->data_tab[1] = (int*)mmap(MMAP_ARGS(SMALL_MAX * sizeof(int)));
	ft_bzero(g_mapping.small->data_tab[0], SMALL_MAX);
	ft_bzero(g_mapping.small->data_tab[1], SMALL_MAX);
}

void	        *malloc_small(size_t size)
{
	void		*res;
	int			i;

	i = 0;
	if (g_mapping.small == NULL)
		init_zone_small();
	else
	{
		while (zone_is_full_small(g_mapping.small) && g_mapping.small->next != NULL)
			g_mapping.small = g_mapping.small->next;
		if (zone_is_full_small(g_mapping.small) && g_mapping.small->next == NULL)
			g_mapping.small = add_zone_small();
	}
	while (g_mapping.small->data_tab[0][i])
		i++;
	g_mapping.small->data_tab[0][i] = 1;
	g_mapping.small->data_tab[1][i] = size;
	res = g_mapping.small->addr + (i * SMALL_ALLOC_SIZE);
	while (g_mapping.small->prev)
		g_mapping.small = g_mapping.small->prev;
	return (res);
}