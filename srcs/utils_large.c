/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_large.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vico <vico@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 11:16:16 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 15:24:35 by vico        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

size_t	large_zone_size(size_t size)
{
	if (size % PAGESIZE == 0)
		return (size);
	else
		return ((size / PAGESIZE + 1) * PAGESIZE);
}

int		is_in_large(void *ptr)
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
