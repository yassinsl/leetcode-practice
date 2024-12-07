/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylahssin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:04:22 by ylahssin          #+#    #+#             */
/*   Updated: 2024/12/06 00:32:30 by ylahssin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_specifier(const char **format, t_list *list, t_flags *flags)
{
	if (**format == 'd' || **format == 'i')
		ft_handle_format(va_arg(list->args, int), flags, list);
	else if (**format == 'c')
		ft_print_char(va_arg(list->args, int), flags, list);
	else if (**format == 's')
		ft_print_str(va_arg(list->args, char *), flags, list);
	else if (**format == 'x' || **format == 'X')
		ft_print_hex(va_arg(list->args, unsigned int), **format, flags, list);
	else if (**format == 'p')
		ft_print_ptr((unsigned long long)va_arg(list->args, void *), flags,
			list);
	else if (**format == 'u')
		ft_print_un(va_arg(list->args, unsigned int), flags, list);
	else
		ft_putchar('%', &list->count);
}

void	check_flags(const char **format, t_flags *flags)
{
	while (**format)
	{
		if (**format == '-')
		{
			flags->minus = 1;
			flags->zero = 0;
		}
		else if (**format == '0')
			flags->zero = 1;
		else if (**format == '+')
			flags->plus = 1;
		else if (**format == '#')
			flags->hash = 1;
		else if (**format == ' ')
			flags->space = 1;
		else
			break ;
		(*format)++;
	}
	check_num(format, flags);
}

void	ft_process_format(const char **format, t_list *list)
{
	t_flags	flags;

	flags = (t_flags){0};
	while (**format)
	{
		if (**format == '%')
		{
			(*format)++;
			check_flags(format, &flags);
			check_specifier(format, list, &flags);
		}
		else
			ft_putchar(**format, &list->count);
		(*format)++;
	}
}

int	ft_printf(const char *format, ...)
{
	t_list	*list;
	int		result;

	list = malloc(sizeof(t_list));
	if (!format || !list)
		return (-1);
	va_start(list->args, format);
	list->count = 0;
	ft_process_format(&format, list);
	va_end(list->args);
	result = list->count;
	free(list);
	return (result);
}
