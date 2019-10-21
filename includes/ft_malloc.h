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



typedef struct  s_tiny_data
{
    struct s_tiny_data  *next;
    struct s_tiny_data  *prev;
    size_t              size;
    void                *addr;
    int                 data_tab[2][TINY_MAX];
}               t_tiny_data;

typedef struct  s_small_data
{
    struct s_small_data  *next;
    struct s_small_data  *prev;
    size_t              size;
    void                *addr;
    int                 data_tab[2][SMALL_MAX];
}               t_small_data;

typedef struct  s_large_data
{
    struct s_large_data  *next;
    struct s_large_data  *prev;
    size_t              size;
    void                *addr;
}               t_large_data;

typedef struct s_mapping
{
	t_tiny_data		*tiny;
	t_small_data	*small;
	t_large_data	*large;
}				t_mapping;

extern	t_mapping	g_mapping;


void	ft_free(void *ptr);
void	*ft_malloc(size_t size);
void    *malloc_tiny();
void    *malloc_small();
void	*ft_realloc(void *ptr, size_t size);
void	show_alloc_mem();
int     tiny_is_full(t_tiny_data *zone);
int     small_is_full(t_small_data *zone);
int     tiny_is_empty(t_tiny_data *zone);
int     small_is_empty(t_small_data *zone);
int     free_small(void *ptr);
int     free_tiny(void *ptr);
size_t	large_zone_size(size_t size);
int		is_in_tiny(void *ptr);
int		is_in_small(void *ptr);
void	*realloc_tiny(void *ptr, size_t size);
void	*realloc_small(void *ptr, size_t size);
void    ft_print(char *s);
void	put_ui_to_hex(uintmax_t n);
int     display_tiny(t_tiny_data *zone, int i);
int     display_small(t_small_data *zone, int i);
int     display_large(t_large_data *zone);

#endif
