#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

#define BUFFER_SIZE 1024 /* Adjust the buffer size as needed */


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
 * my_getline - Custom getline function for reading user input.
 *
 * Return: A dynamically allocated line of input, or NULL on error or end of
 * input. It is the caller's responsibility to free the allocated memory.
 */
char *my_getline(void)
{
	static char buffer[BUFFER_SIZE];
	char *line = NULL;
	ssize_t line_size = 0;

	while (1)
	{
		ssize_t bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE), i;

		if (bytes_read <= 0)
		{
			if (line_size > 0)
				return (line);
			return (NULL); /* End of input */
		}
		for (i = 0; i < bytes_read; i++)
		{
			char current_char = buffer[i];

			if (current_char == '\n')
			{
				line = realloc(line, line_size + 1);
				if (!line)
				{
					perror("Memory allocation error");
					exit(EXIT_FAILURE);
				}
				line[line_size] = '\0';
				return (line);
			}
			line = realloc(line, line_size + 2);
			if (!line)
			{
				perror("Memory allocation error");
				exit(EXIT_FAILURE);
			}
			line[line_size] = current_char;
			line[line_size + 1] = '\0';
			line_size++;
		}
	}
}


