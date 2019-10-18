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

int	display_large(t_large_data *zone)
{
	put_ui_to_hex((unsigned long)zone->addr);	
	ft_print(" - ");
	put_ui_to_hex((unsigned long)zone->addr + zone->size);
	ft_print(": ");
	ft_putnbr(zone->size);
	ft_print(" octets\n");
	return (zone->size);
}

int    		display_small(t_small_data *zone, int i)
{
	int		res;

	res = 0;
	put_ui_to_hex((unsigned long)zone->addr + (i * SMALL_ALLOC_SIZE));	
	ft_print(" - ");
	put_ui_to_hex((unsigned long)zone->addr + (i * SMALL_ALLOC_SIZE)\
		+ zone->data_tab[1][i]);
	ft_print(": ");
	ft_putnbr(zone->data_tab[1][i]);
	ft_print(" octets\n");
	res = zone->data_tab[1][i];
	return (res);
}

int    		display_tiny(t_tiny_data *zone, int i)
{
	int		res;

	res = 0;
	put_ui_to_hex((unsigned long)zone->addr + (i * TINY_ALLOC_SIZE));	
	ft_print(" - ");
	put_ui_to_hex((unsigned long)zone->addr + (i * TINY_ALLOC_SIZE)\
		+ zone->data_tab[1][i]);
	ft_print(": ");
	ft_putnbr(zone->data_tab[1][i]);
	ft_print(" octets\n");
	res = zone->data_tab[1][i];
	return (res);
}
