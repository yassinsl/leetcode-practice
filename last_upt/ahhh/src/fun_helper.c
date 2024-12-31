/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylahssin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 05:23:59 by ylahssin          #+#    #+#             */
/*   Updated: 2024/12/31 05:24:01 by ylahssin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_free_command(t_list *node)
{
	int	i;

	if (!node)
		return ;
	if (node->argv)
	{
		i = 0;
		while (node->argv[i])
		{
			free(node->argv[i]);
			i++;
		}
		free(node->argv);
	}
}

void	ft_free_all_commands(t_list *node)
{
	t_list	*tmp;

	while (node)
	{
		tmp = node;
		node = node->next;
		ft_free_command(tmp);
		free(tmp);
	}
	free(node);
}

char	*ft_strjoin_three(char *s1, char *s2, char *s3)
{
	char	*tmp;
	char	*result;

	tmp = ft_strjoin(s1, s2);
	result = ft_strjoin(tmp, s3);
	free(tmp);
	return (result);
}
