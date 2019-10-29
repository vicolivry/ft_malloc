/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_malloc.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vico <vico@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/12 13:23:42 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 16:11:46 by vico        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/mman.h>

# define PAGESIZE getpagesize()
# define MMAP_ARGS(s) NULL, s, PROT_READ|PROT_WRITE, MAP_ANON|MAP_PRIVATE, -1, 0

# define TINY_MAX 256
# define TINY_ALLOC_SIZE 512
# define TINY_SIZE_AREA (TINY_MAX * TINY_ALLOC_SIZE)

# define SMALL_MAX 128
# define SMALL_ALLOC_SIZE 1024
# define SMALL_SIZE_AREA (SMALL_MAX * SMALL_ALLOC_SIZE)

typedef struct			s_tiny_data
{
	struct s_tiny_data	*next;
	struct s_tiny_data	*prev;
	size_t				size;
	void				*addr;
	int					data_tab[2][TINY_MAX];
}						t_tiny_data;

typedef struct			s_small_data
{
	struct s_small_data	*next;
	struct s_small_data	*prev;
	size_t				size;
	void				*addr;
	int					data_tab[2][SMALL_MAX];
}						t_small_data;

typedef struct			s_large_data
{
	struct s_large_data	*next;
	struct s_large_data	*prev;
	size_t				size;
	void				*addr;
}						t_large_data;

typedef struct			s_mapping
{
	t_tiny_data			*tiny;
	t_small_data		*small;
	t_large_data		*large;
}						t_mapping;

extern	t_mapping		g_mapping;

void					free(void *ptr);
void					*malloc(size_t size);
void					*malloc_tiny(size_t size);
void					*malloc_small(size_t size);
void					*realloc(void *ptr, size_t size);
void					show_alloc_mem(void);
int						tiny_is_full(t_tiny_data *zone);
int						small_is_full(t_small_data *zone);
int						tiny_is_empty(t_tiny_data *zone);
int						small_is_empty(t_small_data *zone);
int						free_small(void *ptr);
int						free_tiny(void *ptr);
size_t					large_zone_size(size_t size);
int						is_in_tiny(void *ptr);
int						is_in_small(void *ptr);
int						is_in_large(void *ptr);
void					*realloc_tiny(void *ptr, size_t size);
void					*realloc_small(void *ptr, size_t size);
void					ft_print(char *s);
void					put_ui_to_hex(uintmax_t n);
size_t					display_tiny(t_tiny_data *zone, int i);
size_t					display_small(t_small_data *zone, int i);
size_t					display_large(t_large_data *zone);
void					ft_bzero(void *s, size_t n);
void					ft_putnbr(size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
int						ft_strlen(const char *s);

#endif
