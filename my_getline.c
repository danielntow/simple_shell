#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024 /* Adjust the buffer size as needed */

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
		ssize_t i, bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);

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
				line = realloc(line, line_size + 1); /* Fnd a newline,extract the line */
				if (!line)
				{
					perror("Memory allocation error");
					exit(EXIT_FAILURE);
				}
				line[line_size] = '\0';
				return (line);
			}
			line = realloc(line, line_size + 2); /* Append the character to the line */
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

