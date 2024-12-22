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
#define EXIT_EXV 126
#define EXIT_COMMAND 127
#define SUCCESS 0
#define ALL_FAILED "error: malloc failed\n"
#define EXIT_FAILURE 1
#define WIATPID_FAILED "Error: Invalid arguments passed to waitpid.\n"
#define ERROR_MS_AR "arguments are invalid\n"
#define FAILER_FD "No such file or directory\n"
#define EXIT_FAILURE 1
#define LENGHT_PATH 12
#define DOESNT_EXECUTABLE "Error: Cannot execute file: Permission denied\n"
#define COMMAND_FAILED "command not found\n"
#define FAILED_EX "execve: Is a directory\n"
#define PIPE_FILED "pipe: Resource temporarily unavailable\n"
#define FORK_FAILER "fork: Resource temporarily unavailable\n"
#define INVALID_ARGUMENTSn "Invalid arguments\n"
#define RW_FAILER "Read or write failure\n"
//function
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
int ft_strlen(char *s);
#endif 
