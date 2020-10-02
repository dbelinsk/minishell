#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

/*
---- NOT INCLUDED IN MINISHELL PROGRAM ----
Simple test function that creates child process,
executes echo comand while main process is waiting to
child process to be finished.
TO COMPILE --->> gcc test.c
TO RUN ----->> ./a.out
*/
void		echo(char *str)
{
	pid_t		child = fork();
	if (child == 0)
	{
		int ret;
		char *cmd[] = {"echo", str, 0 };
		ret = execve ("/bin/echo", cmd, NULL);
	}
	else if (child > 0)
		wait(NULL);
	else
		printf("error\n");
}

int			main()
{
	echo("Hi echo1");
	echo("Hi echo2");
	return (0);
}
