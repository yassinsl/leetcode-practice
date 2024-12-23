#ifndef PIPEX_H
#define PIPEX_H

#include <sys/wait.h>
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
#define PIPE_FAILED "pipe: Resource temporarily unavailable\n"
#define FORK_FAILER "fork: Resource temporarily unavailable\n"
#define INVALID_ARGUMENTSn "Invalid arguments\n"
#define RW_FAILER "Read or write failure\n"
//function
size_t	ft_strlcpy(char *dest, char *src, size_t size);
char *ft_strjoin(char *s1, char  *s2);
void execute_pipeline(t_list *command, s_name *name, int ac, char **env); 
char *ft_strchr( char *str, int c);
char	**ft_split(char  *s, char c);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
int ft_strlen(char *s);
void get_fd(t_list *list, s_name *name, int idx);
void take_io_file_name(int index, s_name *name, char *args);
char *check_path(char *path, char **env);
char *get_path(char *cmd, char **env);
char *ft_strjoin_three(char *s1, char *s2, char *s3);
void ft_free_node(t_list *node);
void ft_perror(char *msg , int num);
t_list *tokenize_cmd(char **args, int argc, s_name *name);
void take_io_file_name(int index, s_name *name, char *args);
int ft_strncmp( char *s1, char *s2, size_t n);
#endif 
