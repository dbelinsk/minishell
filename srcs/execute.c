#include "minishell.h"

/**
 ** HERE COMES TO DO LIST FOR MINISHELL
 */
int				execute(t_command cmd)
{
	ft_putendl_fd(cmd.type, 1);
	ft_putendl_fd(cmd.path, 1);
	ft_putendl_fd(cmd.content, 1);
	ft_putnbr_fd(cmd.flag, 1);
	ft_putchar('\n');
	ft_putnbr_fd(cmd.sep, 1);
	ft_putchar('\n');
	return (1);
}
