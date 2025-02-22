/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylahssin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 05:23:13 by ylahssin          #+#    #+#             */
/*   Updated: 2024/12/31 05:23:15 by ylahssin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	handle_pipe(t_list *command, t_name *name)
{
	if (pipe(name->pipe_fd) == -1)
		ft_perror(PIPE_FAILED, EXIT_FAILURE);
	command->output = name->pipe_fd[1];
}

void	waiting_parents(int *pid, int count_command)
{
	int	i;

	i = 0;
	while (i < count_command)
		waitpid(pid[i++], NULL, 0);
}

void	process_command(t_list *command, t_name *name)
{
	t_list	*tmp;

	tmp = command;
	name->command_index = 0;
	while (tmp)
	{
		if (name->command_index == 0)
			handle_first_command(tmp, name);
		if (tmp->next == NULL)
			handle_last_command(tmp, name);
		if (tmp->next != NULL)
			handle_pipe(tmp, name);
		name->pid[name->command_index] = fork();
		if (name->pid[name->command_index] == -1)
			ft_perror(FORK_FAILER, EXIT_FAILURE);
		if (name->pid[name->command_index] == 0)
			hna_khdma_process(tmp, name, name->pipe_fd, command);
		close(tmp->input);
		close(tmp->output);
		tmp = tmp->next;
		if (tmp)
			tmp->input = name->pipe_fd[0];
		name->command_index++;
	}
	waiting_parents(name->pid, name->command_index);
}

void	execute_pipeline(t_list *command, t_name *name)
{
	process_command(command, name);
}
