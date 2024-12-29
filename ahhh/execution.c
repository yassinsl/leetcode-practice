/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylahssin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:35:46 by ylahssin          #+#    #+#             */
/*   Updated: 2024/12/26 12:07:36 by ylahssin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void handle_last_command(t_list *command, s_name *name, int ac)
{
    int fd;

    if (name->name_output) 
    {
        fd = open(name->name_output, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1)
            ft_perror(FAILER_FD , EXIT_FAILURE);
        dup2(fd, STDOUT_FILENO);
        close(fd);
    }
}
static void handle_first_command(t_list *command, s_name *name)
{
    int fd;

    if (name->name_input) 
    {
        fd = open(name->name_input, O_RDONLY);
        if (fd == -1)
            ft_perror(FAILER_FD, EXIT_FAILURE);
        dup2(fd, STDIN_FILENO);
        close(fd);
    }
}

static void close_unused_pipes(int *pipes_fd, int *prev_fd) 
{ 
    dup2(pipes_fd[0], STDIN_FILENO);
    close(pipes_fd[0]);
    close(pipes_fd[1]);
}

static void execute_command(t_list *command, char *full_path, char **env) 
{
    if (execve(full_path, command->argv, env) == -1) 
        ft_perror(FAILED_EX, EXIT_COMMAND);
}
static void setup_pipe(int *prev_fd, int *pipes_fd, int i, int last_command) 
{
    if (i < last_command) 
    {
        dup2(pipes_fd[1], STDOUT_FILENO);
        close(pipes_fd[1]);
    }
}
// TODO:just i test this function i need to append the prevfd and the ac in the name
static void child_process(t_list *command, s_name *name, char **env, int *pipes_fd, int *prev_fd, int i, int ac) 
{
    char *full_path;

    full_path = get_path(command->argv[0], env);
    if (!full_path)
        ft_perror("Command not found", EXIT_COMMAND);
    setup_pipe(prev_fd, pipes_fd, i, ac - 3);
    if (i == 0)
        handle_first_command(command, name);
    else if (!command->next)
        handle_last_command(command, name, ac);
    execute_command(command, full_path, env);
}

static void process_command(t_list *command, s_name *name, char **env, int ac) 
{
    int pipes_fd[2], prev_fd = -1;
    pid_t pid[1024];
    int i = 0;

    while (command)
    {
        if (pipe(pipes_fd) == -1)
            ft_perror(PIPE_FAILED, EXIT_FAILURE);
        pid[i] = fork();
        if (pid[i] == -1)
            ft_perror(FORK_FAILER, EXIT_FAILURE);
        if (pid[i] == 0)
            child_process(command, name, env, pipes_fd, &prev_fd, i, ac);
        
        close_unused_pipes(pipes_fd, &prev_fd);
        command = command->next;
        i++;
    }
    int count = i;
    i = 0;
    while (i < count) {
        if (waitpid(pid[i++], NULL, 0) == -1) {
            ft_perror(WIATPID_FAILED, EXIT_FAILURE);
        }
    }
}



void execute_pipeline(t_list *command, s_name *name, int ac, char **env) 
{
    if (!command || !name || ac < 1 || !env)
        ft_perror("Invalid arguments", EXIT_FAILURE);
    process_command(command, name, env, ac);
}

