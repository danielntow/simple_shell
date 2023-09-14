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

/**
 * handleExit - Handle the "exit" command with an optional status.
 *
 * @status: The exit status (an integer) to exit the shell.
 */
void handleExit(int status);

/**
 * handleChildProcess - Handle the logic in the child process.
 *
 * @input: The user input.
 */
void handleChildProcess(char *input);

/**
 * handleParentProcess - Handle the logic in the parent process.
 *
 * @child_pid: The child process ID.
 */
void handleParentProcess(pid_t child_pid);

/**
 * handleExit - Handle the "exit" command with an optional status.
 *
 * @status: The exit status (an integer) to exit the shell.
 */
void handleExit(int status);

/**
 * handleEnv - Handle the "env" command to print the current environment.
 */
void handleEnv(void);

/* Declare the external variable environ */
extern char **environ;

/**
 * my_getline - Custom getline function for reading user input.
 *
 * Return: A dynamically allocated line of input, or NULL on error or end of
 * input. It is the caller's responsibility to free the allocated memory.
 */
char *my_getline(void);

char *customTokenize(char *str, const char *delim, char **saveptr);

/* Function prototypes for handle_env_variable.c */
void handleUnsetenv(char *variable);
void handleSetenv(char *variable, char *value);
void handleSetenvCommand(char *input);
void handleUnsetenvCommand(char *input);

/* handle cd cmd */
void changeToHomeDirectory(void);
void changeToPreviousDirectory(void);
void changeToDirectory(const char *directory);
void handleCdCommand(char *input);

char* findExecutable(char *command);

/* handling commands separated by semicolons */
void tokenizeInput(char *input, char *commands[], size_t *num_commands);
void processCommands(char* input);
/**
 * executeCommands - Execute multiple commands in sequence.
 *
 * @commands: An array of commands to execute.
 * @num_commands: The number of commands in the array.
 */
void executeCommands(char *commands[], size_t num_commands);

#endif /* MAIN_H */

