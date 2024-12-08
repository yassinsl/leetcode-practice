/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylahssin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 23:12:48 by ylahssin          #+#    #+#             */
/*   Updated: 2024/12/05 23:13:36 by ylahssin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_atoi(const char **str)
{
	int	result;

	result = 0;
	while (**str >= '0' && **str <= '9')
	{
		result = result * 10 + (**str - '0');
		(*str)++;
	}
	return (result);
}

void	check_num(const char **format, t_flags *flags)
{
	flags->width = ft_atoi(format);
	if (**format == '.')
	{
		(*format)++;
		flags->precision = ft_atoi(format);
		flags->zero = 0;
		flags->flag_pr = 1;
	}
}

void	ft_print_pad(int pad, char c, t_list *list)
{
	while (pad-- > 0)
		ft_putchar(c, &list->count);
}
