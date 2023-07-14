#include "main.h"
/**
 *execute - function to execute the commands
 *@command: the command that should be executed
 */
void execute(char **command)
{
	char *actual_command = command[0];
	char *command_path = NULL;
	pid_t child;
	int status;
	void (*check_build)(char **);

	check_build = built_in_handeler(command);
	if (check_build)
		check_build(command);

	else
	{
		//check if there is a path directory of the command
		command_path = _which(actual_command);
		if (command_path)
		{
			actual_command = command_path;
		}
		child = fork();
		if (child < 0)
		{
			perror("Error:");
			exit(errno);

		}
		else if (child == 0)
		{
			if (execve(actual_command, command, NULL) == -1)
			{
				perror(actual_command);
				exit(errno);
			}
		}
		else
			wait(&status);
	}
}
/**
 *built_in_handler - dtermines whether the command is built in or not
 *@built_in - command 
 *return: 0 
 */
void (*built_in_handeler(char **builtin))(char **command)
{
	built_in check_built[] = 
	{
		{"cd", _cd}, 
		{"exit", exitt},
		{"env", _printenv},
		{"setenv", _setenv}, 
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};
	int i;

	for (i = 0; i < 5; i++)
	{
		if (check_built[i].name == builtin[0])
			return (check_built[i].func);
	}
	return (0);
}