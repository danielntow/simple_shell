#include "main.h"
#include <stdio.h>
#include <unistd.h>

/**
 * customPrint - Custom print function using write.
 *
 * @str: The string to print.
 */
void customPrint(char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}

	write(STDOUT_FILENO, str, length);
}

