#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 500

/**
 * changeToHomeDirectory - Change to the home directory.
 */
void changeToHomeDirectory(void)
{
	const char *home_dir = getenv("HOME");

	if (home_dir == NULL)
	{
		fprintf(stderr, "HOME environment variable not set\n");
		return;
	}
	if (chdir(home_dir) != 0)
		perror("cd");
}

/**
 * changeToPreviousDirectory - Change to the previous directory.
 */
void changeToPreviousDirectory(void)
{
	const char *prev_dir = getenv("OLDPWD");

	if (prev_dir == NULL)
	{
		fprintf(stderr, "OLDPWD not set\n");
		return;
	}
	if (chdir(prev_dir) != 0)
		perror("cd");
}

/**
 * changeToDirectory - Change to a specified directory.
 *
 * @directory: The directory to change to.
 */
void changeToDirectory(const char *directory)
{
	char current_dir[MAX_INPUT_LENGTH];

	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
	{
		perror("getcwd");
		return;
	}

	if (setenv("OLDPWD", current_dir, 1) != 0)
	{
		perror("setenv OLDPWD");
		return;
	}

	if (chdir(directory) != 0)
	{
		perror("cd");
		return;
	}
}

/**
 * handleCdCommand - Handle the "cd" command.
 *
 * @input: The user input containing the command and arguments.
 */
void handleCdCommand(char *input)
{
	char directory[MAX_INPUT_LENGTH];
	char new_current_dir[MAX_INPUT_LENGTH];
	int parsed = sscanf(input + 2, " %s", directory);

	if (parsed == 0)
		changeToHomeDirectory();
	else if (strcmp(directory, "-") == 0)
		changeToPreviousDirectory();
	else
		changeToDirectory(directory);

	if (getcwd(new_current_dir, sizeof(new_current_dir)) == NULL)
	{
		perror("getcwd");
		return;
	}

	if (setenv("PWD", new_current_dir, 1) != 0)
	{
		perror("setenv PWD");
		return;
	}
}
