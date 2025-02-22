/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylahssin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 20:19:00 by ylahssin          #+#    #+#             */
/*   Updated: 2024/12/31 20:19:36 by ylahssin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct list
{
	char		*cmd;
	char		*path_env;
	char		**argv;
	int			input;
	int			output;
	struct list	*next;

}				t_list;
typedef struct NAME
{
	char		*name_input;
	char		*name_output;
	char		**env;
	int			pipe_fd[2];
	int			per_fd;
	int			ac;
	int			pid[1024];
	int			command_index;

}				t_name;

# define EXIT_EXV 126
# define HERDOC "here_doc"
# define DUP2_FAILED "dup2 failed\n"
# define EXIT_COMMAND 127
# define EXIT_FAILURE 1
# define ALL_FAILED "error: malloc failed\n"
# define SUCCESS 0
# define WAITPID_FAILED "Error: Invalid arguments passed to waitpid.\n"
# define ERROR_MS_AR "arguments are invalid\n"
# define FAILER_FD "No such file or directory\n"
# define LENGHT_PATH 12
# define DOESNT_EXECUTABLE "Error: Cannot execute file: Permission denied\n"
# define COMMAND_FAILED "command not found\n"
# define FAILED_EX "execve: Is a directory\n"
# define PIPE_FAILED "pipe: Resource temporarily unavailable\n"
# define FORK_FAILER "fork: Resource temporarily unavailable\n"
# define INVALID_ARGUMENTS "Invalid arguments\n"
# define RW_FAILER "Read or write failure\n"

void			free_array(char **arr);
void			handle_last_command(t_list *command, t_name *name);
void			handle_first_command(t_list *command, t_name *name);
void			ft_free_all_commands(t_list *node);
void			execute_pipeline(t_list *command, t_name *name);
void			get_fd(t_list *list, t_name *name, int idx);
void			take_io_file_name(int index, t_name *name, char *args);
char			*check_path(char *path, char **env);
char			*get_path(char *cmd, char **env);
char			*ft_strjoin_three(char *s1, char *s2, char *s3);
void			ft_perror(char *msg, int num);
t_list			*tokenize_cmd(char **args, int argc, int is_heredoc);
void			take_io_file_name(int index, t_name *name, char *args);
void			process_command(t_list *command, t_name *name);
void			hna_khdma_process(t_list *command, t_name *name, int *fd,
					t_list *cmd);

#endif
