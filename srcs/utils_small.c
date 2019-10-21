/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_small.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 11:16:24 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 11:16:26 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

int		small_is_full(t_small_data *zone)
{
	size_t	i;

	i = 0;
	while (i < SMALL_MAX)
	{
		if (zone->data_tab[0][i] == 0)
			return (0);
		i++;
	}
	return (1);
}

int		small_is_empty(t_small_data *zone)
{
	size_t i;

	i = 0;
	while (i < SMALL_MAX)
	{
		if (zone->data_tab[0][i] != 0)
			return (0);
		i++;
	}
	return (1);
}

int		is_in_small(void *ptr)
{
	t_small_data	*small;
	int				i;

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
