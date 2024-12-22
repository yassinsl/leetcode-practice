#include "pipex.h"
#include <string.h>
#include <sys/wait.h>
int ft_strlen(char *s)
{
    int len = 0;

    while (s[len])
        len++;
    return len;
}

char	*ft_strjoin(char *s1, char  *s2)
{
	char	*result;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		result[j++] = s1[i++];
	i = 0;
	while (s2[i])
		result[j++] = s2[i++];
	result[j] = '\0';
	return (result);
}

char *ft_strjoin_three(char *s1, char *s2, char *s3)
{
    char *tmp = ft_strjoin(s1, s2);
    char *result = ft_strjoin(tmp, s3); 
    free(tmp);
    return result;
}



void take_io_file_name(int index, s_name *name, char *args)
{
    if(index == 1)
        name->name_input = args;
    else
        name->name_output = args;
}

void ft_perror(char *msg)
{
    write(2, msg, ft_strlen(msg));
    exit(exit_failure);
}

void get_fd(t_list *list, s_name *name, int idx)
{
    if (idx == 1)
    {
        //change this to just read
        list->input = open(name->name_input, o_rdonly, 0777);
        if (list->input == -1)
            ft_perror(failer_fd);
    }
    else
    {
        list->output = open(name->name_output, o_creat | o_wronly | o_trunc, 0777);
        if (list->output == -1)
        {
            close(list->input);
            ft_perror(failer_fd);
        }
    }
}

t_list *tokenize_cmd(char **args, int argc, s_name *name)
{
    t_list *new_node;
    t_list *head = null;
    int last_idx = argc - 1;

    while (--argc >= 1)
    {
        if (argc == 1 || argc == last_idx)
        {
        take_io_file_name(argc, name, args[argc]);
            continue;
        }

        new_node = malloc(sizeof(t_list));
        if (!new_node && !head)
        {
            ft_free_node(head);
            ft_perror("error: malloc failed.\n");
        }
        new_node->cmd = args[argc];
        new_node->argv = ft_split(args[argc], ' ');
        new_node->next = head; 
        head = new_node;
    }
    return head;
}
char *check_path(char *path, char **env)
{
    //just aw9 kantichi nik mok 
    int i = 0;

    while(env[i])
    {
       if(strncmp(path, env[i], 5) == 0)
           return(env[i] + 5);
       i++;
    }
    return(null);
}
char *get_path(char *cmd, char **env)
{
    //todo : jsut the test use the libft project
    char *path,*full_path;
    char **dir;
    int i = 0;
    if(strchr(cmd, '/'))
    {
        if(cmd[0] == '~')
        {
            path = check_path("home=", env);
            full_path = ft_strjoin(path,cmd + 1);
         if(access(full_path, x_ok) == -1)
                ft_perror(doesnt_executable);
         return full_path;
        }
        else 
        { 
            if(access(cmd, x_ok) == -1)
                ft_perror(doesnt_executable);
            return cmd;
        }
    }
    else
    {
            path = check_path("path=", env);
            if(!path)
                return(null);
            dir = ft_split(path , ':');
            while(dir[i])
            {
            full_path = ft_strjoin_three(dir[i], "/", cmd);
            if(access(full_path, x_ok) != -1)
                return(full_path);
            i++; 
            }
    }
    return((void *)0);
}
void ft_close(int *file_fd, int idx)
{
    int i = 0;

    while(i < idx)
        close(file_fd[i++]);
}
void execute_pipeline(t_list *commands, s_name *name, int ac, char **env)
{
    pid_t pid;
    int pipes[2];
    int prev_fd = -1;
    int i = 0;
    char *full_path;
    pid_t last_pid;

    while (commands)
    {
        if (i != ac - 3)
        {
            if (pipe(pipes) == -1)
                ft_perror("error: pipe creation failed.\n");
        }

        full_path = get_path(commands->argv[0], env);
        if (!full_path)
        {
            if (prev_fd != -1)
                close(prev_fd);
            ft_perror("error: command not found or path unset.\n");
        }

        pid = fork();
        if (pid == -1)
            ft_perror("error: fork failed.\n");

        if (pid == 0)
        {
            if (i == 0)
            {
                get_fd(commands, name, 1);
                dup2(commands->input, stdin_fileno);
                close(commands->input);
            }
            else
            {
                dup2(prev_fd, stdin_fileno);
                close(prev_fd);
            }

            if (commands->next)
            {
                dup2(pipes[1], stdout_fileno);
                close(pipes[1]);
            }
            else
            {
                get_fd(commands, name, ac - 1);
                dup2(commands->output, stdout_fileno);
                close(commands->output);
            }

            ft_close(pipes, 2);
            execve(full_path, commands->argv, env);
            ft_perror("error: command execution failed.\n");
        }

        last_pid = pid;
        if (prev_fd != -1)
            close(prev_fd);
        if (commands->next)
            prev_fd = pipes[0];
        close(pipes[1]);

        commands = commands->next;
        i++;
    }

    if (waitpid(last_pid, null, 0) == -1)
        ft_perror("error: waiting for child process failed.\n");
}
int main(int ac, char **av, char **env)
{
    t_list *tokenized_list;
    s_name *name = malloc(sizeof(s_name));

    if (ac < 5)
        ft_perror(error_ms_ar);
    tokenized_list = tokenize_cmd(av, ac, name);
    execute_pipeline(tokenized_list, name, ac, env);
  // while(tokenized_list)
  // {
    //   int i = 0;
     //  while(i <  2)
     //  printf("%s\n", tokenized_list->cmd);
     // tokenized_list = tokenized_list->next;
 // }
    return success;
}
