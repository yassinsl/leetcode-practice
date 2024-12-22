#include "pipex.h"

int main(int ac, char **av, char **env)
{
    t_list *tokenized_list;
    s_name *name = malloc(sizeof(s_name));

    if (ac < 5)
        ft_perror(ERROR_MS_AR, EXIT_FAILURE);
    tokenized_list = tokenize_cmd(av, ac, name);
    execute_pipeline(tokenized_list, name, ac, env);
    ft_free_node(tokenized_list), tokenized_list = NULL;
    free(name), name = NULL;

    return SUCCESS;
}

