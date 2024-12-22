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

char *ft_strjoin_three(char *s1, char *s2, char *s3)
{
    char *tmp = ft_strjoin(s1, s2);
    char *result = ft_strjoin(tmp, s3); 
    free(tmp);
    return result;
}

