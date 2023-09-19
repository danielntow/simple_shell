#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 100

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
 * tokenizeInput - Tokenize a string of commands separated by semicolons.
 *
 * @input: The input string containing multiple commands.
 * @commands: An array to store the individual commands.
 * @num_commands: Pointer to the number of commands found.
 */
void tokenizeInput(char *input, char *commands[], size_t *num_commands)
{
	char *token;
	*num_commands = 0;
	token = strtok(input, ";");

	while (token != NULL && *num_commands < (MAX_INPUT_LENGTH / 2))
	{
		commands[(*num_commands)++] = token;
		token = strtok(NULL, ";");
	}
}

/**
 * executeCommands - Execute multiple commands in sequence.
 *
 * @commands: An array of commands to execute.
 * @num_commands: The number of commands in the array.
 */
void executeCommands(char *commands[], size_t num_commands)
{
	size_t i;

	for (i = 0; i < num_commands; i++)
	{
		char *command = commands[i];

		if (strncmp(command, "exit", 4) == 0)
		{
			int status = 0;

			if (sscanf(command + 4, " %d", &status) == 1)
				handleExit(status);
			else
				handleExit(0);
		}
		else if (strncmp(command, "setenv", 6) == 0)
			handleSetenvCommand(command);
		else if (strncmp(command, "unsetenv", 8) == 0)
			handleUnsetenvCommand(command);
		else if (strncmp(command, "cd", 2) == 0)
			handleCdCommand(command);
		else
		{
			pid_t child_pid = fork();

			if (child_pid == -1)
			{
				perror("Error forking");
				exit(EXIT_FAILURE);
			}
			if (child_pid == 0)
			{
				handleChildProcess(command);
				exit(EXIT_SUCCESS);
			}
			else
				handleParentProcess(child_pid);
		}
	}
}

/**
 * processCommands - Process and execute multiple commands separated by
 * semicolons.
 *
 * @input: The input string containing multiple commands.
 */
void processCommands(char *input)
{
	char *commands[MAX_INPUT_LENGTH / 2];
	size_t num_commands = 0;

	tokenizeInput(input, commands, &num_commands);

	executeCommands(commands, num_commands);
}





