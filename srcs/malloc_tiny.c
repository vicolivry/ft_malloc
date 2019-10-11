
#include "../includes/ft_malloc.h"

static t_page_data	*add_zone_tiny()
{
	g_mapping.tiny->next = mmap(MMAP_ARGS(sizeof(t_page_data)));
	if (g_mapping.tiny->next == NULL)
		return (NULL);
	g_mapping.tiny->next->prev = g_mapping.tiny;
	g_mapping.tiny = g_mapping.tiny->next;
	g_mapping.tiny->addr = mmap(MMAP_ARGS(TINY_SIZE_AREA));	
	g_mapping.tiny->type = TINY;
	g_mapping.tiny->next = NULL;
	g_mapping.tiny->size = TINY_SIZE_AREA - sizeof(t_page_data);
	g_mapping.tiny->data_tab = (int**)mmap(MMAP_ARGS(2 * sizeof(int*)));
	g_mapping.tiny->data_tab[0] = (int*)mmap(MMAP_ARGS(TINY_MAX * sizeof(int)));
	g_mapping.tiny->data_tab[1] = (int*)mmap(MMAP_ARGS(TINY_MAX * sizeof(int)));
	ft_bzero(g_mapping.tiny->data_tab[0], TINY_MAX);
	ft_bzero(g_mapping.tiny->data_tab[1], TINY_MAX);
	return (g_mapping.tiny);
}

static void		init_zone_tiny()
{
	g_mapping.tiny = mmap(MMAP_ARGS(sizeof(t_page_data)));
	if (g_mapping.tiny == NULL)
		return ;
	g_mapping.tiny->addr = mmap(MMAP_ARGS(TINY_SIZE_AREA));
	g_mapping.tiny->type = TINY;
	g_mapping.tiny->next = NULL;
	g_mapping.tiny->prev = NULL;
	g_mapping.tiny->size = TINY_SIZE_AREA - sizeof(t_page_data);
	g_mapping.tiny->data_tab = (int**)mmap(MMAP_ARGS(2 * sizeof(int*)));
	g_mapping.tiny->data_tab[0] = (int*)mmap(MMAP_ARGS(TINY_MAX * sizeof(int)));
	g_mapping.tiny->data_tab[1] = (int*)mmap(MMAP_ARGS(TINY_MAX * sizeof(int)));
	ft_bzero(g_mapping.tiny->data_tab[0], TINY_MAX);
	ft_bzero(g_mapping.tiny->data_tab[1], TINY_MAX);
}

void	        *malloc_tiny(size_t size)
{
	void		*res;
	int			i;

	i = 0;
	if (g_mapping.tiny == NULL)
		init_zone_tiny();
	else
	{
		while (zone_is_full(g_mapping.tiny, TINY_MAX) && g_mapping.tiny->next != NULL)
			g_mapping.tiny = g_mapping.tiny->next;
		if (zone_is_full(g_mapping.tiny, TINY_MAX) && g_mapping.tiny->next == NULL)
			g_mapping.tiny = add_zone_tiny();
	}
	while (g_mapping.tiny->data_tab[0][i])
		i++;
	g_mapping.tiny->data_tab[0][i] = 1;
	g_mapping.tiny->data_tab[1][i] = size;
	res = g_mapping.tiny->addr + (i * TINY_ALLOC_SIZE);
	while (g_mapping.tiny->prev)
		g_mapping.tiny = g_mapping.tiny->prev;
	return (res);
}