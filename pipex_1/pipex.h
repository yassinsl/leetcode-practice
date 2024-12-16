#ifndef PIPEX_H
#define PIPEX_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
typedef struct list
{
	char *cmd;
    char *path_env;
	char **argv;
	int input;
	int output;
	struct list *next;

} t_list;
typedef struct NAME
{
    char *name_input;
    char *name_output;
} s_name;
//difine help
#define ERROR_MS_AR "arguments are invalid\n"
#define FAILER_FD "No such file or directory\n"
#define EXIT_FAILURE 1
#define SUCCESS 0

//function
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
int ft_strlen(char *s);
#endif
