/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_num_flags_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylahssin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 03:22:00 by ylahssin          #+#    #+#             */
/*   Updated: 2024/12/06 03:28:20 by ylahssin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_nhex(unsigned long n, int len, t_list *list, char *base)
{
	char	buffer[16];
	int		i;

	i = len - 1;
	while (i >= 0)
	{
		buffer[i] = base[n % 16];
		n /= 16;
		i--;
	}
	i = 0;
	while (i < len)
	{
		ft_putchar(buffer[i], &list->count);
		i++;
	}
}

int	ft_lenhex(unsigned long long n, int base)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		count++;
		n /= base;
	}
	return (count);
}

static void	ft_print_hex_prefix(unsigned int nb, char format, t_flags *flags,
		t_list *list)
{
	if (flags->hash && nb)
	{
		ft_putchar('0', &list->count);
		ft_putchar(format, &list->count);
	}
}

static void	ft_print_hex_padding(int pad, t_flags *flags, t_list *list,
		int is_zero)
{
	if (!flags->minus && pad > 0 && (!flags->zero || flags->flag_pr
			|| !is_zero))
		ft_print_pad(pad, ' ', list);
	if (flags->zero && !flags->flag_pr && is_zero && pad > 0)
		ft_print_pad(pad, '0', list);
}

void	ft_print_hex(unsigned int nb, char format, t_flags *flags, t_list *list)
{
	char	*base;

	int (len), (zeros), (pad), (prefix_len);
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	len = ft_lenhex(nb, 16);
	if (nb == 0 && flags->flag_pr && flags->precision == 0)
		len = 0;
	zeros = 0;
	if (flags->precision > len)
		zeros = flags->precision - len;
	prefix_len = 0;
	if (flags->hash && nb)
		prefix_len = 2;
	pad = flags->width - (len + zeros + prefix_len);
	ft_print_hex_padding(pad, flags, list, 1);
	ft_print_hex_prefix(nb, format, flags, list);
	if (zeros > 0)
		ft_print_pad(zeros, '0', list);
	if (!(nb == 0 && flags->flag_pr && flags->precision == 0))
		print_nhex(nb, len, list, base);
	if (flags->minus && pad > 0)
		ft_print_pad(pad, ' ', list);
}
