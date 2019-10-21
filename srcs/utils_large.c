/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_large.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 11:16:16 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 11:16:18 by volivry     ###    #+. /#+    ###.fr     */
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
