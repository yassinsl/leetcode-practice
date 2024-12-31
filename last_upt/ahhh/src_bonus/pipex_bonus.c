/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylahssin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 20:19:57 by ylahssin          #+#    #+#             */
/*   Updated: 2024/12/31 20:20:09 by ylahssin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*read_here_doc(char *limit, int ac)
{
	char	*random_str;
	int		fd;
	char	*line;

	if (ac < 6)
		return (NULL);
	random_str = "nicmok";
	fd = open(random_str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (NULL);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (ft_strncmp(limit, line, ft_strlen(limit)) == 0
			&& line[ft_strlen(limit)] == '\n')
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	return (close(fd), random_str);
}

static t_name	*initialize_and_validate(int ac, char **env)
{
	t_name	*name;

	name = malloc(sizeof(t_name));
	if (!name)
		ft_perror(ALL_FAILED, EXIT_FAILURE);
	name->env = env;
	name->ac = ac;
	if (name->ac < 5)
	{
		free(name);
		ft_perror(ERROR_MS_AR, EXIT_FAILURE);
	}
	return (name);
}

static void	process_and_execute(int ac, char **av, t_name *name)
{
	t_list	*tokenized_list;

	tokenized_list = NULL;
	if (!ft_strncmp(av[1], HERDOC, ft_strlen(HERDOC)))
	{
		name->name_input = read_here_doc(av[2], name->ac);
		if (!name->name_input)
		{
			free(name);
			ft_perror(ERROR_MS_AR, EXIT_COMMAND);
		}
		tokenized_list = tokenize_cmd(av, name->ac - 2, 1);
	}
	else
	{
		name->name_input = av[1];
		tokenized_list = tokenize_cmd(av, name->ac - 2, 0);
	}
	name->name_output = av[ac - 1];
	execute_pipeline(tokenized_list, name);
	ft_free_all_commands(tokenized_list);
	free(name);
}

int	main(int ac, char **av, char **env)
{
	t_name	*name;

	name = initialize_and_validate(ac, env);
	process_and_execute(ac, av, name);
	return (SUCCESS);
}
