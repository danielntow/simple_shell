#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * handleSetenv - Handle the "setenv" command to initialize or modify an
 * environment variable.
 *
 * @variable: The name of the environment variable.
 * @value: The value to set for the environment variable.
 */
void handleSetenv(char *variable, char *value)
{
	/* Check if both variable and value are provided */
	if (variable == NULL || value == NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return;
	}

	/* Use the setenv function to set the environment variable */
	if (setenv(variable, value, 1) != 0)
	{
		perror("setenv");
		fprintf(stderr, "Failed to set environment variable: %s\n", variable);
	}
}

/**
 * handleUnsetenv - Handle the "unsetenv" command to remove an environment
 * variable.
 *
 * @variable: The name of the environment variable to remove.
 */
void handleUnsetenv(char *variable)
{
	/* Check if the variable name is provided */
	if (variable == NULL)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return;
	}

	/* Use the unsetenv function to remove the environment variable */
	if (unsetenv(variable) != 0)
	{
		perror("unsetenv");
		fprintf(stderr, "Failed to unset environment variable: %s\n", variable);
	}
}

