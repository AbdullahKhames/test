#include "shell.h"
extern char** environ;
/**
 * execute_command - func to execute_command
 * @command: command to be executed
*/
void execute_command(char* command) {
    pid_t pid = fork();

    if (pid < 0) {
        // Error occurred during vfork
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        char* arguments[] = { command, NULL };
        execve(command, arguments, environ);

        // If the execution reaches this point, it means the command was not found
        fprintf(stderr, "Command '%s' not found.\n", command);
        exit(1);
    } else {
        // Parent process
        waitpid(pid, NULL, 0);
    }
}

/**
 * prompt_user - func to prompt_user
*/
void prompt_user() {
    printf("$ ");
    fflush(stdout);
}

