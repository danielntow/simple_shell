#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 100

/**
 * handleExit - Handle the "exit" command with an optional status.
 *
 * @status: The exit status (an integer) to exit the shell.
 */
void handleExit(int status)
{
	exit(status);
}

/**
 * handleEnv - Handle the "env" command to print the current environment.
 */
void handleEnv(void)
{
	char **env = environ;

	while (*env)
	{
		customPrint(*env);
		customPrint("\n");
		env++;
	}
}

/**
 * handleChildProcess - Handle the logic in the child process.
 *
 * @input: The user input.
 */
void handleChildProcess(char *input)
{
	executeCommand(input);
}

/**
 * handleParentProcess - Handle the logic in the parent process.
 *
 * @child_pid: The child process ID.
 */
void handleParentProcess(pid_t child_pid)
{
	int status;

	(void)child_pid; /* Mark the parameter as unused */

	wait(&status);

	if (WIFEXITED(status))
	{
		char status_str[10];

		snprintf(status_str, sizeof(status_str), "%d", WEXITSTATUS(status));
		customPrint("Child process exited with status ");
		customPrint(status_str);
		customPrint("\n");
	}
	else
	{
		customPrint("Child process did not exit normally\n");
	}
}

/**
 * executeCommand - Execute a command in the child process.
 *
 * @input: The user input containing the command.
 */
void executeCommand(char *input)
{
	/* Parse the command and arguments */
	char *args[MAX_INPUT_LENGTH / 2];
	char *token = strtok(input, " ");
	int i = 0;

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	/* Execute the command */
	if (execvp(args[0], args) == -1)
	{
		perror("Error executing command");
		exit(EXIT_FAILURE);
	}
}