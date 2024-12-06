/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_flags_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylahssin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 03:16:45 by ylahssin          #+#    #+#             */
/*   Updated: 2024/12/06 03:26:31 by ylahssin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_handle_padding(int pad, char pad_char, t_list *list)
{
	if (pad > 0)
		ft_print_pad(pad, pad_char, list);
}

static void	ft_print_sign(t_flags *flags, t_list *list)
{
	if (flags->plus || flags->space)
	{
		if (flags->plus)
			ft_putchar('+', &list->count);
		else
			ft_putchar(' ', &list->count);
	}
}

static void	ft_print_number_and_zeros(unsigned int nb, int zeros, int len,
		t_list *list)
{
	if (zeros > 0)
		ft_print_pad(zeros, '0', list);
	if (nb != 0 || len > 0)
		print_number(nb, len, list);
}

void	ft_print_un(unsigned int nb, t_flags *flags, t_list *list)
{
	int	len;
	int	is_signed;
	int	zeros;
	int	pad;

	len = ft_len(nb, 10);
	if (nb == 0 && flags->flag_pr && flags->precision == 0)
		len = 0;
	is_signed = (flags->plus || flags->space);
	if (flags->precision > len)
		zeros = flags->precision - len;
	else
		zeros = 0;
	pad = flags->width - (len + zeros + is_signed);
	if (!flags->minus && (!flags->zero || flags->flag_pr))
		ft_handle_padding(pad, ' ', list);
	ft_print_sign(flags, list);
	if (flags->zero && !flags->flag_pr)
		ft_handle_padding(pad, '0', list);
	ft_print_number_and_zeros(nb, zeros, len, list);
	if (flags->minus)
		ft_handle_padding(pad, ' ', list);
}
