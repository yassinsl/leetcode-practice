/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_flags_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylahssin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 03:23:13 by ylahssin          #+#    #+#             */
/*   Updated: 2024/12/06 03:23:47 by ylahssin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_number(long long n, int len, t_list *list)
{
	char	buffer[12];
	int		i;

	i = len - 1;
	while (1)
	{
		buffer[i] = (n % 10) + '0';
		if (!n)
			break ;
		n /= 10;
		i--;
	}
	i = 0;
	while (i < len)
	{
		ft_putchar(buffer[i], &list->count);
		i++;
	}
}

int	ft_len(long long n, int base)
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

static void	handle_padding_and_sign(int nb, t_flags *flags, t_list *list,
		int pad)
{
	if (!flags->minus && pad > 0 && (!flags->zero || flags->flag_pr))
		ft_print_pad(pad, ' ', list);
	if (nb < 0)
		ft_putchar('-', &list->count);
	else if (flags->plus)
		ft_putchar('+', &list->count);
	else if (flags->space)
		ft_putchar(' ', &list->count);
	if (flags->zero && !flags->flag_pr && pad > 0)
		ft_print_pad(pad, '0', list);
}

void	ft_handle_format(int nb, t_flags *flags, t_list *list)
{
	long long	n;

	int (len), (is_signed), (zeros), (pad);
	if (nb == 0 && flags->flag_pr && flags->precision == 0)
		len = 0;
	else
		len = ft_len(nb, 10);
	is_signed = 0;
	if (flags->plus || flags->space || nb < 0)
		is_signed = 1;
	zeros = 0;
	if (flags->precision > len)
		zeros = flags->precision - len;
	pad = flags->width - (len + zeros + is_signed);
	if (nb < 0)
		n = -(long long)nb;
	else
		n = nb;
	handle_padding_and_sign(nb, flags, list, pad);
	if (zeros > 0)
		ft_print_pad(zeros, '0', list);
	if (!(n == 0 && flags->flag_pr && flags->precision == 0))
		print_number(n, len, list);
	if (flags->minus && pad > 0)
		ft_print_pad(pad, ' ', list);
}
