/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_malloc.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/12 13:23:42 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 13:23:45 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/mman.h>

# define PAGESIZE sysconf(_SC_PAGESIZE)
# define MMAP_ARGS(size) NULL, PAGESIZE, PROT_READ|PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0
# define TINY_MIN 1
# define TINY_MAX 40
# define TINY_SIZE_AREA PAGESIZE
# define SMALL_MIN TINY_MAX + 1
# define SMALL_MAX 80
# define SMALL_SIZE_AREA PAGESIZE * 2
# define LARGE_MIN SMALL_MAX + 1



void	ft_free(void *ptr);
void	*ft_malloc(size_t size);
void	*ft_realloc(void *ptr, size_t size);
void	show_alloc_mem();

#endif
