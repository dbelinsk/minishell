#include "minishell.h"

int		get_cmd(char **line)
{
	ft_putstr_fd("mpernia ~/Documents/minishell/\n", 1);
	ft_putstr_fd("$ ", 1);
	if (get_next_line(1, line) < 0)
		return (0);
	return (1);
}
