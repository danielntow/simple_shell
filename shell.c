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
	/* Read user input using custom my_getline function */
	char *line = my_getline();

	if (line == NULL)
	{
		/* End of input or error, exit gracefully */
		exit(EXIT_SUCCESS);
	}

	/* Copy the line into the input buffer */
	strncpy(input, line, MAX_INPUT_LENGTH);
	input[MAX_INPUT_LENGTH - 1] = '\0';

	/* Calculate the length of the input */
	*input_length = strlen(input);

	/* Free the allocated memory for the line */
	free(line);

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
		char *full_path = (char *)malloc(strlen(token) + strlen(command) + 2);

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

		/* Check if the user entered "exit" */
		if (strcmp(input, "exit") == 0)
			handleExit();

		/* Fork a child process */
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error forking");
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			/* Child process */
			handleChildProcess(input);
		}
		else
		{
			/* Parent process */
			handleParentProcess(child_pid);
		}
	}
}

