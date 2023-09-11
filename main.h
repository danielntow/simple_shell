#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>

/**
 * readInput - Read user input.
 *
 * @input: The buffer to store the user input.
 * @input_length: Pointer to the length of the input.
 *
 * Return: 0 on success, -1 on failure.
 */
int readInput(char input[], size_t *input_length);

/**
 * executeCommand - Execute a command in the child process.
 *
 * @input: The user input containing the command.
 */
void executeCommand(char *input);

/**
 * runShell - Run a simple shell program.
 */
void runShell(void);

/**
 * customPrint - Custom print function using write.
 *
 * @str: The string to print.
 */
void customPrint(char *str);

#endif /* MAIN_H */

