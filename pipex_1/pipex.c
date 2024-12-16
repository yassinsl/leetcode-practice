#include "pipex.h"

void ft_free_node(t_list *node)
{
    t_list *tmp;

    while(node)
    {
        tmp = node;
        node = node->next;
        free(tmp);
    }
    free(node);
}
int ft_strlen(char *s)
{
    int len = 0;

    while (s[len])
        len++;
    return len;
}

void take_IO_file_name(int index, s_name *name, char *args)
{
    if(index == 1)
        name->name_input = args;
    else
        name->name_output = args;
  //  printf("%s", name->name_output);
        //printf("%s\n", (index == 1) ? name->name_input :"hello");
}
void ft_perror(char *msg)
{
    write(2, msg, ft_strlen(msg));
    exit(EXIT_FAILURE);
}

void get_fd(t_list *list, char *arg, int idx)
{
    if (idx == 0)
    {
        list->input = open(arg, O_RDONLY);
        if (list->input == -1)
            ft_perror(FAILER_FD);
    }
    else
    {
        list->output = open(arg, O_CREAT | O_WRONLY | O_TRUNC, 0777);
        if (list->output == -1)
        {
            close(list->input);
            ft_perror(FAILER_FD);

    }
}

t_list *tokenize_cmd(char **args, int argc)
{
    t_list *new_node;
    t_list *head = NULL;
    s_name *name = malloc(sizeof(s_name));
    int last_idx = argc - 1;

    while (--argc >= 1)
    {
        if (argc == 1 || argc == last_idx)
        {
        take_IO_file_name(argc, name, args[argc]);
            continue;
        }

        new_node = malloc(sizeof(t_list));
        if (!new_node && !head)
        {
            ft_free_node(head);
            ft_perror("Error: Malloc failed.\n");
        }
        new_node->cmd = args[argc];
        new_node->argv = ft_split(args[argc], ' ');
        new_node->next = head; 
        head = new_node;
    }
    return head;
}

int main(int ac, char **av, char **env)
{
    t_list *tokenized_list;

    if (ac < 5)
        ft_perror(ERROR_MS_AR);
    tokenized_list = tokenize_cmd(av, ac);
    
    while(tokenized_list)
    {
        printf("%s\n", tokenized_list->cmd);
       tokenized_list = tokenized_list->next;
   }
    return SUCCESS;
}
