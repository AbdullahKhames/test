#include "shell.h"

/**
 * StrToArr - function to split line to tokens
 * @src: line to be splitted
 * @delimeters: to split upon
 * @n: number of tokens generated
 * Return: returns string array of tokens
*/
char **StrToArr(char *src, char *delimeters, int *n){

    char *token;
    int numberOfTokens = 0;
    int i;
    char **tokens = malloc(sizeof(char *) * _strlen(src));

    if (!tokens){
        return NULL;
    }
    if (!src){
        return NULL;
    }
    if (!delimeters){
        return NULL;
    }

    token = _strtok(src,delimeters);
    if (token == NULL){
        return NULL;
    }

    tokens[numberOfTokens++] = token;
    while (token != NULL)
    {
        token = _strtok(NULL, delimeters);
        tokens[numberOfTokens++] = token;
    }
    tokens[numberOfTokens] = NULL;
    *n = --numberOfTokens;
    return (tokens);
}

/**
 * _strlen - function to get length of str
 * @src: thhe string to get its length
 * Return: returns number of chars in string
*/
int _strlen(char *src)
{
    int i = 0;
    for ( i = 0; src[i] != '\0'; i++)
    ;

    return i;
}

/**
 * _strtok - function to get token
 * @src: line to be splitted
 * @delimeters: to split upon
 * Return: returns string token
*/

char *_strtok(char *src, char *delimeters)
{
    static char *temp = NULL;
    char *token;
    int i;
    int len = _strlen(delimeters);
    if (src != NULL){
        temp = src;
    }

    if (temp == NULL){
        return NULL;
    }
    token = temp;

    while (*temp != '\0')
    {
        for (i = 0; i < len; i++)
        {
            if (*temp == delimeters[i]){

                *temp = '\0';

                temp++;
                return token;
            }
        }
        temp++;

        
    }
     temp = NULL;
     return (token);

    
}

size_t _strcspn(const char *str) {
    size_t length = 0;
    while (str[length] != '\n' && str[length] != '\0') {
        length++;
    }
    return length;
}
