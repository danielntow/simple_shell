#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 100

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(void)
{
	/* Run the shell program */
	runShell();
	return (0);
}

