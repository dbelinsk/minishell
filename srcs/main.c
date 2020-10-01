#include "minishell.h"

int				m_error()
{
	ft_putstr_fd("Error: Failed to read cmd\n", 1);
	return (1);
}

int				m_exit(char **to_free)
{
	free(*to_free);
	*to_free = NULL;
	return (0);
}

int				main()
{
	char *line = NULL;

	while (1)
	{
		if (!get_cmd(&line))
			return (m_error());
		if (!ft_strncmp("exit", line, 4))
			return (m_exit(&line));
		free(line);
		line = NULL;
	}
	return (0);
}
