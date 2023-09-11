#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <unistd.h>

/**
 * readInput - Read user input.
 *
 * @input: The buffer to store the user input.
 * @input_length: Pointer to the length of the input.
 *
 * Return: 0 on success, -1 on failure.
 */
int readInput(char input[], size_t* input_length);

/**
 * executeCommand - Execute a command in the child process.
 *
 * @input: The user input containing the command.
 */
void executeCommand(char* input);

/**
 * runShell - Run a simple shell program.
 */
void runShell(void);

/**
 * customPrint - Custom print function using write.
 *
 * @str: The string to print.
 */
void customPrint(char* str);

/**
 * handleExit - Handle the "exit" command.
 */
void handleExit(void);

/**
 * handleChildProcess - Handle the logic in the child process.
 *
 * @input: The user input.
 */
void handleChildProcess(char* input);

/**
 * handleParentProcess - Handle the logic in the parent process.
 *
 * @child_pid: The child process ID.
 */
void handleParentProcess(pid_t child_pid);

/**
 * handleExit - Handle the "exit" command.
 */
void handleExit(void);

/**
 * handleEnv - Handle the "env" command to print the current environment.
 */
void handleEnv(void);

/* Declare the external variable environ */
extern char **environ;

#endif /* MAIN_H */

