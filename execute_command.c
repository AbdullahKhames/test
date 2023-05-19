#include "shell.h"
extern char** environ;
/**
 * execute_command - func to execute_command
 * @command: command to be executed
*/
void execute_command(char* command) {
    pid_t pid = fork();
    char* arguments[] = { command, NULL };
    
    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        
        execve(command, arguments, environ);

        fprintf(stderr, "Command '%s' not found.\n", command);
        exit(1);
    } else {
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

