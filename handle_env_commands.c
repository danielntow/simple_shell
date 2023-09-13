#include "main.h"
#include <stdio.h>

#define MAX_INPUT_LENGTH 100

/**
 * handleSetenvCommand - Handle the "setenv" command.
 *
 * @input: The user input containing the command and arguments.
 */
void handleSetenvCommand(char *input)
{
	char variable[MAX_INPUT_LENGTH];
	char value[MAX_INPUT_LENGTH];
	int parsed = sscanf(input + 6, " %s \"%[^\"]\"", variable, value);

	if (parsed == 2)
		handleSetenv(variable, value);
	else
		fprintf(stderr, "Usage: setenv VARIABLE \"VALUE\"\n");
}

/**
 * handleUnsetenvCommand - Handle the "unsetenv" command.
 *
 * @input: The user input containing the command and arguments.
 */
void handleUnsetenvCommand(char *input)
{
	char variable[MAX_INPUT_LENGTH];
	int parsed = sscanf(input + 8, " %s", variable);

	if (parsed == 1)
		handleUnsetenv(variable);
	else
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
}
