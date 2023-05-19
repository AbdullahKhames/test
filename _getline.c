#include "shell.h"

/**
 * _getline - function to get line
 * @line: address of pointer to line
 * @initialSize: address to initial size
 * Return: bytes read
*/
ssize_t _getline(char **line, int *initialSize){
    int bytes_read = 0;
    char c;
    ssize_t totalBytes = 0;
    char *temp;

    if (!line || !initialSize){
        return 0;
    }

    *line = (char *) malloc(sizeof(char) * (*initialSize));

     if (*line == NULL){
        perror("malloc");
        return 0;
    }

    while (1)
    {
        bytes_read = read(STDIN_FILENO, &c, 1);
        if (bytes_read == -1)
        {
            perror("read");
            return (-1);
        }
        else if (bytes_read == 0)
        {
            break;
        }
        else if (c == '\n')
        {
            break;
        }
        else{
            if (totalBytes >= *initialSize - 1)
            {
                *initialSize *= 2;
                temp = (char*)realloc(*line, *initialSize);
                if (temp == NULL){
                    perror("realloc");
                    break;
                }
                (*line) = temp;

            }
            (*line)[totalBytes] = c;
            totalBytes++;
        }
    }
    if (totalBytes > 0){
        (*line)[totalBytes] = '\0';
    }
    printf("%s\n", *line);
    return totalBytes;
}

