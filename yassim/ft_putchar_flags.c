/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylahssin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 23:10:58 by ylahssin          #+#    #+#             */
/*   Updated: 2024/12/05 23:11:52 by ylahssin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_print_char(char c, t_flags *flags, t_list *list)
{
	int	pad;

	pad = flags->width - 1;
	if (!flags->minus)
		ft_print_pad(pad, ' ', list);
	ft_putchar(c, &list->count);
	if (flags->minus)
		ft_print_pad(pad, ' ', list);
}
