/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylahssin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 23:36:36 by ylahssin          #+#    #+#             */
/*   Updated: 2024/12/05 23:48:01 by ylahssin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	va_list	args;
	int		count;
}			t_list;

typedef struct s_flags
{
	int		minus;
	int		plus;
	int		zero;
	int		space;
	int		hash;
	int		width;
	int		precision;
	int		flag_pr;
}			t_flags;

int			ft_printf(const char *format, ...);
void		check_num(const char **format, t_flags *flags);
void		ft_print_pad(int pad, char c, t_list *list);
void		check_specifier(const char **format, t_list *list, t_flags *flags);
void		check_flags(const char **format, t_flags *flags);
void		ft_process_format(const char **format, t_list *list);
void		ft_putchar(char c, int *count);
void		print_nhex(unsigned long n, int len, t_list *list, char *base);
int			ft_lenhex(unsigned long long n, int base);
void		ft_print_hex(unsigned int nb, char format, t_flags *flags,
				t_list *list);
void		print_number(long long n, int len, t_list *list);
int			ft_len(long long n, int base);
void		print_sign(int nb, t_flags *flags, t_list *list);
void		handle_padding(int pad, t_flags *flags, t_list *list);
void		ft_handle_format(int nb, t_flags *flags, t_list *list);
void		ft_print_ptr(unsigned long long nb, t_flags *flags, t_list *list);
void		ft_putstr(char *str, int len, t_list *list);
int			ft_strlen(char *str);
void		ft_print_un(unsigned int nb, t_flags *flags, t_list *list);
void		ft_print_char(char c, t_flags *flags, t_list *list);
void		ft_print_str(char *str, t_flags *flag, t_list *list);

#endif
