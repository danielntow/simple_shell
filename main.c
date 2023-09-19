#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 1024



void execute_command(const char *command);

/**
 * main - Entry point of the shell program.
 *
 * Description: Reads user input, executes commands, and exits o"exit" command.
 *
 * Return: Always returns 0.
 */
int main(void)
{
char input[BUFFER_SIZE];

while (1)
{
printf("$ ");
fgets(input, BUFFER_SIZE, stdin);

input[strlen(input) - 1] = '\0';

if (strcmp(input, "exit") == 0)
{
	printf("Exiting the shell...\n");
	break;
}

execute_command(input);
}

return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * execute_command - Execute a given command.
 *
 * @command: The command to execute.
 *
 * Description: Forks a child process to execute the commandand waits for it to
 * complete.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * execute_command - Execute a given command.
 *
 * @command: The command to execute.
 *
 * Description: Forks a child process to execute the command
 */
void execute_command(const char *command)
{
pid_t pid = fork();
char *args[64];
char *token;
int i;

if (pid == -1)
{
perror("Fork failed");
}
else if (pid == 0)
{
char command_copy[BUFFER_SIZE];
strcpy(command_copy, command);
token = strtok(command_copy, " ");
i = 0;

while (token != NULL)
{
	args[i++] = token;
	token = strtok(NULL, " ");
}

args[i] = NULL;

if (execvp(args[0], args) == -1)
{
	perror("Command execution failed");
	exit(EXIT_FAILURE);
}
}
else
{
int status;
waitpid(pid, &status, 0);
}
}
