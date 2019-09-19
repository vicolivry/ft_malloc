/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_malloc.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/12 15:25:46 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 15:25:47 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"
#include <errno.h>

void	*ft_malloc(size_t size)
{
    errno = 0;

	ft_printf("Len = %d\n", size);
    ft_printf("change");
	ft_printf("Pagesize = %d\n", PAGESIZE);
	ft_printf("Mmap return = %d\n", mmap(MMAP_ARGS(PAGESIZE)));
	// ft_printf("Mmap return = %d\n", mmap(NULL, PAGESIZE, PROT_READ|PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0));
	ft_printf("ERROR: %s\n", strerror(errno));
	ft_printf("Real malloc return = %x\n", malloc(3));

    return (0);
}