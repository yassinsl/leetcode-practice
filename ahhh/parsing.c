#include "pipex.h"

char *check_path(char *path, char **env)
{
    int i = 0;

    while(env[i])
    {
       if(ft_strncmp(path, env[i], 5) == 0)
           return(env[i] + 5);
       i++;
    }
    return(NULL);
}

char *get_path(char *cmd, char **env)
{
    char *path,*full_path;
    char **dir;
    int i = 0;
    if(ft_strchr(cmd, '/'))
    {
        if(cmd[0] == '~')
        {
            path = check_path("HOME=", env);
            full_path = ft_strjoin(path,cmd + 1);
         if(access(full_path, X_OK) == -1)
                ft_perror(DOESNT_EXECUTABLE, EXIT_EXV);
         return full_path;
        }
        else 
        { 
            if(access(cmd, X_OK) == -1)
                ft_perror(DOESNT_EXECUTABLE, EXIT_EXV);
            return (cmd);
        }
    }
    else
    {
            path = check_path("PATH=", env);
            if(!path)
                return(NULL);
            dir = ft_split(path , ':');
            while(dir[i] && dir[i][0])
            {
            full_path = ft_strjoin_three(dir[i], "/", cmd);
            if(access(full_path, X_OK) != -1)
                return(full_path);
            i++; 
            }
            //if(!dir[i][0]) ft_perror("command not found\n", 1);
    }
    return((void *)0);
}
void take_io_file_name(int index, s_name *name, char *args)
{
    if(index == 1)
        name->name_input = args;
    else
        name->name_output = args;
}


void get_fd(t_list *list, s_name *name, int idx)
{
    if (idx == 1)
    {
        list->input = open(name->name_input, O_RDONLY);
        if (list->input == -1)
            ft_perror(FAILER_FD, EXIT_COMMAND);
    }
    else
    {
        list->output = open(name->name_output, O_CREAT | O_WRONLY| O_TRUNC, 0777);
        if (list->output == -1)
        {
            close(list->input);
            ft_perror(FAILER_FD, EXIT_COMMAND);
        }
    }
}
t_list *tokenize_cmd(char **args, int argc, s_name *name)
{
    t_list (*new_node), (*head);
    int last_idx = argc - 1;
    head = NULL;
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
            ft_perror(ALL_FAILED, EXIT_FAILURE);
        }
        new_node->cmd = args[argc];
        new_node->argv = ft_split(args[argc], ' ');
        new_node->next = head;
        head = new_node;
    }
    return head;
}

