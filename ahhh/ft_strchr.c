/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylahssin <ylahssin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:39:27 by ylahssin          #+#    #+#             */
/*   Updated: 2024/12/21 07:23:58 by ylahssin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strchr(char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

/*
#include <stdio.h>

//#include <string.h>

int	main(void)
{
	const char	*str = "hello";
	char		ch;
	char		*result;

	ch = 'e';
	result = ft_strchr(str, ch);
	printf("Character '%s'", result);
	return (0);
}*/
