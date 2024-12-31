/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylahssin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 05:05:21 by ylahssin          #+#    #+#             */
/*   Updated: 2024/12/31 05:05:42 by ylahssin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	pid_t	pid[1024];
	int		command_index;

	command_index = 0;
	while (command)
	{
		if (command_index == 0)
			handle_first_command(command, name);
		if (command->next == NULL)
			handle_last_command(command, name);
		if (command->next != NULL)
			handle_pipe(command, name);
		pid[command_index] = fork();
		if (pid[command_index] == -1)
			ft_perror(FORK_FAILER, EXIT_FAILURE);
		if (pid[command_index] == 0)
			hna_khdma_process(command, name, name->pipe_fd);
		close(command->input);
		close(command->output);
		command = command->next;
		if (command)
			command->input = name->pipe_fd[0];
		command_index++;
	}
	waiting_parents(pid, command_index);
}

void	execute_pipeline(t_list *command, t_name *name)
{
	if (!command || !name || !name->env)
		ft_perror("Invalid arguments", EXIT_FAILURE);
	process_command(command, name);
}
