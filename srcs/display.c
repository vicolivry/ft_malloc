#include "../includes/ft_malloc.h"

void 		ft_print(char *s)
{
  write(1, s, ft_strlen(s));
}

void		put_ui_to_hex(uintmax_t n)
{
	static char	list[] = "0123456789abcdef";
	uintmax_t	tmp;
	int			digits;
	char		output[15];

	tmp = n;
	digits = 1;
	while (tmp /= 16)
		digits++;
	tmp = n;
    output[digits] = '\0';
	while (digits--)
	{
		output[digits] = list[tmp % 16];
		tmp /= 16;
	}
    ft_print("0x");
	ft_print(output);
}

static int	display_large(t_page_data *zone)
{
	put_ui_to_hex((unsigned long)zone->addr);	
	ft_print(" - ");
	put_ui_to_hex((unsigned long)zone->addr + zone->size);
	ft_print(": ");
	ft_putnbr(zone->size);
	ft_print(" octets\n");
	return (zone->size);
}

int    		display_alloc_mem(t_page_data *zone, int i)
{
	int		res;
	size_t	alloc_size;

	res = 0;
	if (zone->type != LARGE)
	{
		alloc_size = zone->type == TINY ? TINY_ALLOC_SIZE : SMALL_ALLOC_SIZE;
		put_ui_to_hex((unsigned long)zone->addr + (i * alloc_size));	
		ft_print(" - ");
		put_ui_to_hex((unsigned long)zone->addr + (i * alloc_size)\
			+ zone->data_tab[1][i]);
		ft_print(": ");
		ft_putnbr(zone->data_tab[1][i]);
		ft_print(" octets\n");
		res = zone->data_tab[1][i];
	}
	else
		res = display_large(zone);
	return (res);
}