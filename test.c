#include "shell.h"
extern char** environ;

#define MAX_COMMAND_LENGTH 100
int main() {
    char* command = NULL;
    int command_len = 0;

    while (1) {
        prompt_user();

        if (_getline(&command, &command_len) == -1) {
            printf("\n");
            break;
        }

        /*command[_strcspn(command)] = '\0';*/

        char* token = _strtok(command, " ");

        if (token != NULL) {
            execute_command(token);
        }
    }

    free(command);

    return 0;
}
