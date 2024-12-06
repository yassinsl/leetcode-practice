# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylahssin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 14:11:54 by ylahssin          #+#    #+#              #
#    Updated: 2024/12/06 00:28:12 by ylahssin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a

SRCS = ft_fun_helper.c ft_putchar_flags.c ft_putstr_flags.c \
       ft_printf.c ft_put_hex_num_flags.c ft_putptr_flags.c ft_putunbr_flags.c ft_putnbr_flags.c

SRCS_BN = ft_fun_helper_bonus.c ft_putchar_flags_bonus.c ft_putnbr_flags_bonus.c ft_putstr_flags_bonus.c \
          ft_printf_bonus.c ft_put_hex_num_flags_bonus.c ft_putptr_flags_bonus.c ft_putunbr_flags_bonus.c

OBJCS = $(SRCS:.c=.o)

OBJCS_BN = $(SRCS_BN:.c=.o)

RM = rm -rf

CC = cc

CFLAGS = -Wall -Werror -Wextra

SLIB = ar rcs

all: $(NAME)

$(NAME): $(OBJCS)
	$(SLIB) $(NAME) $(OBJCS)

bonus: $(OBJCS) $(OBJCS_BN)
	$(SLIB) $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJCS) $(OBJCS_BN)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY :
