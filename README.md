# Simple Shell

Simple Shell is a basic UNIX command-line interpreter written in C. It is designed to emulate some of the functionality of the standard UNIX shell (/bin/sh). This project is part of a learning process and aims to explore the fundamentals of operating systems and system calls.

## Learning Objectives

At the end of this project, you are expected to be able to explain:

### General
1. Who designed and implemented the original Unix operating system.
2. Who wrote the first version of the UNIX shell.
3. Who invented the B programming language (the direct predecessor to the C programming language).
4. Who is Ken Thompson.
5. How does a shell work.
6. What is a pid and a ppid.
7. How to manipulate the environment of the current process.
8. What is the difference between a function and a system call.
9. How to create processes.
10. What are the three prototypes of the main function.
11. How does the shell use the PATH to find programs.
12. How to execute another program with the execve system call.
13. How to suspend the execution of a process until one of its children terminates.
14. What is EOF ("end-of-file")?

### Copyright - Plagiarism
- Avoid plagiarism. Do not copy and paste someone else's work.

## Requirements

### General
- Allowed editors: vi, vim, emacs.
- Compilation: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
- All code files should end with a newline.
- Include a README.md file.
- Follow the Betty style guide.
- Your shell should not have any memory leaks.
- No more than 5 functions per file.
- All header files should be include guarded.
- Use system calls only when necessary.
- Create a README with the description of your project.
- Include an AUTHORS file at the root of your repository, listing all contributors.

### Output
- Your program must have the same output as /bin/sh.
- The name of the program must be equivalent to argv[0] when printing errors.

### List of Allowed Functions and System Calls
- access, chdir, close, closedir, execve, exit, _exit, fflush, fork, free, getcwd, getline, getpid, isatty, kill, malloc, open, opendir, perror, read, readdir, signal, stat, lstat, fstat, strtok, wait, waitpid, wait3, wait4, write.

## Compilation

Your shell will be compiled as follows:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


## Testing

Your shell should work in both interactive and non-interactive modes. Here are some examples:

### Interactive Mode
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

### Non-Interactive Mode
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$


## Tasks

1. **Betty would be proud**: Ensure your code follows the Betty style guide.

2. **Simple shell 0.1**: Write a basic UNIX command-line interpreter that displays a prompt and executes simple commands. Handle errors.

3. **Simple shell 0.2**: Extend the shell to handle command lines with arguments.

4. **Simple shell 0.3**: Implement the PATH handling and ensure that fork is not called if the command doesn't exist.

5. **Simple shell 0.4**: Implement the `exit` built-in command to exit the shell.

6. **Simple shell 1.0**: Implement the `env` built-in command to print the current environment.

7. **Simple shell 0.1.1**: Write your own `getline` function without using the `getline` function from the standard library.

8.  **Simple shell 0.2.1**: Implement command parsing without using `strtok`.

9. **Simple shell 0.4.1**: Handle arguments for the built-in `exit` command.

10. **setenv, unsetenv**: Implement the `setenv` and `unsetenv` built-in commands to manage environment variables.

11. **cd**: Implement the `cd` built-in command to change the current directory.

12. **;**: Handle the `;` command separator.

13. **&& and ||**: Handle the `&&` and `||` shell logical operators.

14. **alias**: Implement the `alias` built-in command to manage aliases.

15. **Variables**: Handle variable replacement, including `$?` and `$$`.

16. **Comments**: Handle comments (lines starting with `#`).

17. **File as input**: Allow the shell to take a file as a command line argument, executing commands from the file.

## Usage

To use this shell, compile the source code and run the resulting executable:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
./hsh



##Contributors
PRINCE OFOSU
DANIEL NTOW 



##License
This project is licensed under the PRINCE OFOSU AND DANIEL NTOW License - see the LICENSE.md file for details.


This README file outlines the project's objectives, requirements, tasks, and usage instructions, making it a comprehensive guide for anyone interested in your simple shell project.
