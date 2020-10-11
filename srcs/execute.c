#include "minishell.h"

int				s_exit(t_command **cmd)
{
	int		ret = 0;
	if ((*cmd)->sep == PIPE)
		ret = 1;
	clean_cmd(cmd);
	return (ret);
}

int				s_echo(t_command **cmd)
{
	int		ret = 1;

	ft_putstr_fd((*cmd)->content, 1);
	if (!(*cmd)->flag)
		ft_putchar_fd('\n', 1);
	clean_cmd(cmd);
	return (ret);
}
/**
 ** HERE COMES TO DO LIST FOR MINISHELL
 */
int				execute(t_command **cmd)
{
	printf("type = [%s]\n", (*cmd)->type);
	printf("path = [%s]\n", (*cmd)->path);
	printf("content = [%s]\n", (*cmd)->content);
	printf("flag = [%d]\n", (*cmd)->flag);
	printf("sep = [%d]\n", (*cmd)->sep);
	if ((*cmd)->exe)
		return (*cmd)->exe(cmd);
	return (1);
}
