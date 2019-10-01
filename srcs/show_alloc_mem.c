/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   show_alloc_mem.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/01 11:26:59 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/01 11:27:00 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "../includes/ft_malloc.h"

void	show_alloc_mem()
{
	t_page_data	*header;

	header = g_mapping.tiny + 1;
	if (g_mapping.tiny != NULL)
	{
		write(1, "TINY: ", 6);
		ft_printf("%p\n", g_mapping.tiny);
	}
	while (header->next != NULL)
	{
		ft_printf("0x%x - 0x%x : %d octets\n", header, (void*)header + 12, header->alloc_size);
		header = header->next;
	}
}