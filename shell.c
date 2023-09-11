#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 100

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 100

/**
 * readInput - Read user input.
 *
 * @input: The buffer to store the user input.
 * @input_length: Pointer to the length of the input.
 *
 * Return: 0 on success, -1 on failure.
 */
int readInput(char input[], size_t *input_length)
{
	/* Read user input */
	if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
	{
		if (feof(stdin))
		{
			/* End of file (Ctrl+D) detected, exit gracefully */
			exit(EXIT_SUCCESS);
		}
		perror("Error reading input");
		return (-1);
	}

	/* Remove trailing newline character, if present */
	*input_length = strlen(input);
	if (*input_length > 0 && input[*input_length - 1] == '\n')
	{
		input[*input_length - 1] = '\0';
		(*input_length)--;
	}

	return (0);
}

/**
 * findExecutable - Find the full path of the executable based on PATH.
 *
 * @command: The command to find.
 *
 * Return: Full path to the executable, or NULL if not found.
 */
char *findExecutable(char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *token;

	if (path_copy == NULL)
	{
		perror("Error duplicating PATH");
		exit(EXIT_FAILURE);
	}

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		char *full_path =
		    (char *)malloc(strlen(token) + strlen(command) + 2);

		if (full_path == NULL)
		{
			perror("Error allocating memory");
			free(path_copy);
			exit(EXIT_FAILURE);
		}

		sprintf(full_path, "%s/%s", token, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
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
	char *full_path;

	int i = 0;

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	/* Find the full path of the executable */
	full_path = findExecutable(args[0]);
	if (full_path == NULL)
	{
		customPrint("Command not found: ");
		customPrint(args[0]);
		customPrint("\n");
		exit(EXIT_FAILURE);
	}

	/* Execute the command */
	if (execv(full_path, args) == -1)
	{
		perror("Error executing command");
		free(full_path);
		exit(EXIT_FAILURE);
	}

	free(full_path);
}

/**
 * runShell - Run a simple shell program.
 */
void runShell(void)
{
	while (1)
	{
		char input[MAX_INPUT_LENGTH];
		size_t input_length;
		pid_t child_pid;

		/* Display a prompt with $ */
		customPrint("$ ");

		/* Read user input */
		if (readInput(input, &input_length) == -1)
			exit(EXIT_FAILURE);

		/* Fork a child process */
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error forking");
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
			executeCommand(input);
		else
		{
			/* Parent process */
			int status;

			wait(&status);
			if (WIFEXITED(status))
			{
				customPrint("Child process exited with status ");
				customPrint("\n");
			}
			else
				customPrint("Child process did not exit normally\n");
		}
	}
}


