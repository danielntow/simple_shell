#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 100

/**
 * runShell - Run a simple shell program.
 */

void runShell(void)
{
	while (1)
	{
		char input[MAX_INPUT_LENGTH];
		size_t input_length = 0;

		customPrint("$ ");

		if (readInput(input, &input_length) == -1)
			exit(EXIT_FAILURE);

		processCommands(input);
	}
}
