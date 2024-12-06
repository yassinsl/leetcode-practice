/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_helper_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylahssin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 03:16:01 by ylahssin          #+#    #+#             */
/*   Updated: 2024/12/06 03:16:15 by ylahssin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
