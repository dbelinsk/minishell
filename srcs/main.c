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

/*
--- Default shell command ignores spaces ---
Cleans up all spaces, tabs, ...
Result = formated cmd to work with.
*/
void			format_cmd(char **line)
{
	char		*tmp;
	int			has_sp;
	int			i;
	char		fmt[ft_strlen(*line)];

	tmp = *line;
	has_sp = 0;
	i = 0;
	while (*tmp && ft_isspace(*tmp))
		tmp++;
	while (*tmp)
	{
		if (ft_isspace(*tmp))
			has_sp++;
		if (!ft_isspace(*tmp) && has_sp >= 1)
			has_sp = 0;
		if (has_sp <= 1 )
			fmt[i++] = *tmp;
		tmp++;
	}
	fmt[i] = 0;
	free(*line);
	*line = ft_strdup(fmt);
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
		format_cmd(&line);
		ft_putstr_fd("[",1);
		ft_putstr_fd(line, 1);
		ft_putstr_fd("]\n",1);
		free(line);
		line = NULL;
	}
	return (0);
}
