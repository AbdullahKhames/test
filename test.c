#include "shell.h"
extern char** environ;

#define MAX_COMMAND_LENGTH 100
int main() {
    char* command = NULL;
    int command_len = 0;

    while (1) {
        prompt_user();

        // Read the command from the user
        if (_getline(&command, &command_len) == -1) {
            // End of file condition (Ctrl+D)
            printf("\n");
            break;
        }

        // Remove the newline character at the end
        command[_strcspn(command)] = '\0';

        // Tokenize the command
        char* token = _strtok(command, " ");

        if (token != NULL) {
            // Execute the command
            execute_command(token);
        }
    }

    free(command);

    return 0;
}
