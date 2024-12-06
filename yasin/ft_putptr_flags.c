/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylahssin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:24:17 by ylahssin          #+#    #+#             */
/*   Updated: 2024/12/05 23:56:29 by ylahssin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_nil(t_flags *flags, t_list *list)
{
	int	len;
	int	pad;

	len = 0;
	if (flags->flag_pr && flags->precision == 0)
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
	print_nhex(nb, len, list, "0123456789abncdef");
}

void	ft_print_ptr(unsigned long long nb, t_flags *flags, t_list *list)
{
	int	len;
	int	zeros;
	int	pad;

	len = ft_lenhex(nb, 16);
	if (nb == 0)
	{
		ft_print_nil(flags, list);
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
