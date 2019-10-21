/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_tiny.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 11:16:32 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 11:16:33 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

int		tiny_is_empty(t_tiny_data *zone)
{
	size_t i;

	i = 0;
	while (i < TINY_MAX)
	{
		if (zone->data_tab[0][i] != 0)
			return (0);
		i++;
	}
	return (1);
}

int		is_in_tiny(void *ptr)
{
	t_tiny_data	*tiny;
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

int		tiny_is_full(t_tiny_data *zone)
{
	size_t	i;

	i = 0;
	while (i < TINY_MAX)
	{
		if (zone->data_tab[0][i] == 0)
			return (0);
		i++;
	}
	return (1);
}
