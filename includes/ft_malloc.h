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

# define PAGESIZE getpagesize()
# define MMAP_ARGS(size) NULL, size, PROT_READ|PROT_WRITE, MAP_ANON|MAP_PRIVATE, -1, 0

# define TINY_MAX 512
# define TINY_ALLOC_SIZE 16
# define TINY_SIZE_AREA PAGESIZE * 2

# define SMALL_MAX 112
# define SMALL_ALLOC_SIZE 512
# define SMALL_SIZE_AREA PAGESIZE * 14

# define LARGE_MIN SMALL_ALLOC_SIZE + 1

# define TINY 0
# define SMALL 1
# define LARGE 2



typedef struct  s_page_data
{
    struct s_page_data  *next;
    struct s_page_data  *prev;
    size_t              size;
    int                 type;
    void                *addr;
    int                 **data_tab;
}               t_page_data;

typedef struct s_mapping
{
	t_page_data	*tiny;
	t_page_data	*small;
	t_page_data	*large;
}				t_mapping;

extern	t_mapping	g_mapping;


void	ft_free(void *ptr);
void	*ft_malloc(size_t size);
void    *malloc_tiny();
void    *malloc_small();
void	*ft_realloc(void *ptr, size_t size);
void	show_alloc_mem();

#endif
