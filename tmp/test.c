#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

/*
---- NOT INCLUDED IN MINISHELL PROGRAM ----
Cheet sheat for all alowed functions
*/

/*
Creates child process, parent process waits until child process is finished.
Child process exejutes function execve
*/
void		fork_wait_execve_example(char *str)
{
	pid_t		child = fork();
	if (child == 0)
	{
		int ret;
		char *cmd[] = {"echo", "-n", str, 0 };
		ret = execve ("/bin/echo", cmd, NULL);
	}
	else if (child > 0)
		wait(&child);
	else
		printf("error\n");
}

/*waitpid doesn't block the process*/
void waitpid_example(char *str)
{
	pid_t		pid = fork();
	pid_t		cpid;
	int			stat;

	if (pid == 0)
	{
		int ret;
		char *cmd[] = {"echo", str, 0 };
		ret = execve ("/bin/echo", cmd, NULL);
		exit(0);
	}
	printf("IF THIS LINE APEARS BEFORE [%s] --> means that child proces din't finished yet\n", str);
	cpid = waitpid(pid, &stat, 0);
	if (WIFEXITED(stat))
		printf("Child %d terminated with status: %d\n", cpid, WEXITSTATUS(stat));
}

void		signal_example()
{
	signal()
}

int			main()
{
	printf("*********** waitpid_example ***********\n");
	waitpid_example("HELLO WAITPID");
	printf("*********** fork_wait_execve_example ***********\n");
	fork_wait_execve_example("Hi echo1");
	printf("\n*********** signal_example ***********\n");
	return (0);
}
