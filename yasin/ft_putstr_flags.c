/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylahssin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 22:20:16 by ylahssin          #+#    #+#             */
/*   Updated: 2024/12/05 23:42:57 by ylahssin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_min(int len, int presicion)
{
	if (len < presicion)
		return (len);
	return (presicion);
}

void	ft_putstr(char *str, int len, t_list *list)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_putchar(str[i], &list->count);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_print_str(char *str, t_flags *flag, t_list *list)
{
	int	len;
	int	pad;

	if (str == NULL && flag->flag_pr && flag->precision < 6)
		str = "";
	else if (flag->flag_pr && flag->precision == 0)
		str = "";
	else if (str == NULL)
		str = "(null)";
	if (flag->precision > 0)
		len = ft_min(ft_strlen(str), flag->precision);
	else
		len = ft_strlen(str);
	if (flag->width > len)
		pad = flag->width - len;
	else
		pad = 0;
	if (!flag->minus && pad > 0)
		ft_print_pad(pad, ' ', list);
	ft_putstr(str, len, list);
	if (flag->minus)
		ft_print_pad(pad, ' ', list);
}
