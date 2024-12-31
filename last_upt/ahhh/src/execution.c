#include "pipex.h"

void	handle_last_command(t_list *command, t_name *name)
{
	int	fd;

	if (name->name_output)
	{
		fd = open(name->name_output, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			ft_perror(FAILER_FD, EXIT_FAILURE);
		command->output = fd;
	}
}

void	handle_first_command(t_list *command, t_name *name)
{
	int	fd;

	if (name->name_input)
	{
		fd = open(name->name_input, O_RDONLY);
		if (fd == -1)
			ft_perror(FAILER_FD, EXIT_FAILURE);
		command->input = fd;
	}
}

void	execute(t_list *command, t_name *name)
{
	char	*full_path;

	full_path = get_path(command->argv[0], name->env);
	if (!full_path)
	{
		ft_free_all_commands(command);
		ft_perror(COMMAND_FAILED, EXIT_FAILURE);
	}
	if (execve(full_path, command->argv, name->env) == -1)
	{
		free(full_path);
		ft_perror(FAILED_EX, EXIT_COMMAND);
	}
	free(full_path);
}

void	hna_khdma_process(t_list *command, t_name *name, int *fd)
{
	if (dup2(command->input, STDIN_FILENO) == -1)
	{
		close(fd[1]);
		ft_perror(DUP2_FAILED, EXIT_FAILURE);
	}
	if (dup2(command->output, STDOUT_FILENO) == -1)
	{
		close(fd[1]);
		ft_perror(DUP2_FAILED, EXIT_FAILURE);
	}
	close(command->output);
	close(command->input);
	close(name->pipe_fd[0]);
	execute(command, name);
}
