void setup_pipes(t_list *commands) {
    // Create pipes for inter-process communication
    // Allocate pipe file descriptors
}

void execute_pipeline(t_list *commands, char **env) {
    pid_t pid;
    int pipe_count = count_commands(commands);
    int pipes[2][2];  // Array to manage multiple pipes

    // Iterate through commands
    for (int i = 0; i < pipe_count; i++) {
        // Create pipes
        if (i < pipe_count - 1) {
            if (pipe(pipes[i % 2]) == -1) {
                // Handle pipe creation error
            }
        }

        pid = fork();
        if (pid == 0) {  // Child process
            // Redirect input/output
            // Close unused pipe ends
            // Execute command
            execve(...);
        } else if (pid > 0) {  // Parent process
            // Close used pipe ends
            // Prepare for next iteration
        }
    }

    // Parent waits for all child processes
    while (wait(NULL) > 0);
}
void execute_pipeline(t_list *commands, s_name *name, int ac, char **env)
{
    pid_t pid;
    int pipes[2];
    int prev_fd = -1; // Store previous pipe's output
    int i = 0;
    char *full_path;

    while (++i < ac - 1 && commands)
    {
        pipe(pipes); // Create a new pipe
        pid = fork();
        if (pid == 0)
        {
            // Child process
            if (i == 1) // First command: read from input file
                get_fd(commands, name, i);
            else if (i == ac - 2) // Last command: write to output file
                get_fd(commands, name, i);
            else // Middle commands: read from previous pipe
                dup2(prev_fd, STDIN_FILENO);

            dup2(pipes[1], STDOUT_FILENO); // Write to current pipe
            close(pipes[0]);
            close(pipes[1]);

            // Execute the command
            full_path = get_path(commands->argv[0], env);
            if (!full_path)
                ft_perror("Error: Command not found\n");
            execve(full_path, commands->argv, env);
        }
        else
        {
            // Parent process
            waitpid(pid, NULL, 0); // Wait for child to finish
            close(pipes[1]);
            if (prev_fd != -1) // Close previous pipe
                close(prev_fd);
            prev_fd = pipes[0]; // Update previous pipe
        }
        commands = commands->next; // Move to next command
    }
}
