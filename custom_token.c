#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/**
 * customTokenize - Custom string tokenizer.
 *
 * @str: The string to tokenize (or NULL to continue tokenization).
 * @delim: The delimiter character.
 * @saveptr: A pointer to a char* to store the current position in the string.
 *
 * Return: The next token in the string, or NULL if no more tokens are found.
 */
char *customTokenize(char *str, const char *delim, char **saveptr)
{
	char *start, *end;

	if (str == NULL && *saveptr == NULL)
		return (NULL);

	start = (str != NULL) ? str : *saveptr;
	end = start;

	/* Skip leading delimiter characters */
	while (*start != '\0' && strchr(delim, *start) != NULL)
	{
		start++;
		end++;
	}

	/* Find the end of the token */
	while (*end != '\0' && strchr(delim, *end) == NULL)
	{
		end++;
	}

	/* If no token is found, return NULL */
	if (start == end)
	{
		*saveptr = NULL;
		return (NULL);
	}

	/* Null-terminate the token */
	if (*end != '\0')
	{
		*end = '\0';
		end++;
	}

	*saveptr = end;
	return (start);
}

