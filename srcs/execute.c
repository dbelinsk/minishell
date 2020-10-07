#include "minishell.h"

/**
 ** HERE COMES TO DO LIST FOR MINISHELL
 */
int				execute(t_command cmd)
{
	printf("type = [%s]\n", cmd.type);
	printf("path = [%s]\n", cmd.path);
	printf("content = [%s]\n", cmd.content);
	printf("flag = [%d]\n", cmd.flag);
	printf("sep = [%d]\n", cmd.sep);
	printf("***************************\n");
	return (1);
}
