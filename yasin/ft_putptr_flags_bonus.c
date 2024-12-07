/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_flags_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylahssin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:01:01 by ylahssin          #+#    #+#             */
/*   Updated: 2024/12/07 14:01:04 by ylahssin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_nil(long long nb, t_flags *flags, t_list *list)
{
	int	len;
	int	pad;

	len = 0;
	if (!nb && !((flags->flag_pr && flags->precision == 0)))
		len = ft_strlen("(nil)");
	else if (flags->flag_pr && flags->precision == 0)
		len = 0;
	else
		ft_strlen("(nil)");
	pad = flags->width - len;
	if (!flags->minus && pad > 0)
		ft_print_pad(pad, ' ', list);
	if (!(flags->flag_pr && flags->precision == 0))
		ft_putstr("(nil)", len, list);
	if (flags->minus && pad > 0)
		ft_print_pad(pad, ' ', list);
}

static void	ft_print_ptr_prefix(t_list *list)
{
	ft_putstr("0x", 2, list);
}

static void	ft_print_hex_number(unsigned long long nb, int zeros, int len,
		t_list *list)
{
	if (zeros > 0)
		ft_print_pad(zeros, '0', list);
	print_nhex(nb, len, list, "0123456789abcdef");
}

void	ft_print_ptr(unsigned long long nb, t_flags *flags, t_list *list)
{
	int	len;
	int	zeros;
	int	pad;

	len = ft_lenhex(nb, 16);
	if (nb == 0)
	{
		ft_print_nil(nb, flags, list);
		return ;
	}
	if (flags->precision > len)
		zeros = flags->precision - len;
	else
		zeros = 0;
	pad = flags->width - (len + zeros + 2);
	if (!flags->minus && pad > 0 && (!flags->zero || flags->flag_pr))
		ft_print_pad(pad, ' ', list);
	ft_print_ptr_prefix(list);
	ft_print_hex_number(nb, zeros, len, list);
	if (flags->minus && pad > 0)
		ft_print_pad(pad, ' ', list);
}
