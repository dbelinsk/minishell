/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 21:19:13 by mpernia-          #+#    #+#             */
/*   Updated: 2020/10/02 22:43:39 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**Prompt from cmd, it waits for command and print dir by using getcwd()
*/
int		get_cmd(char **line)
{
	char *dir;

	dir = NULL;
	dir = getcwd(dir, 0);
	ft_putstr_fd(dir, 1);
	ft_putstr_fd("\n$ ", 1);
	free(dir);
	if (get_next_line(1, line) < 0)
		return (0);
	return (1);
}

/*
--- Default shell command ignores spaces ---
Cleans up all spaces, tabs, ...
Result = formated cmd to work with.
*/
void	format_cmd(char **line)
{
	char	*tmp;
	char	fmt[ft_strlen(*line)];
	int		has_sp;
	int		i;

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

/*
**Check if echo have a /n or not, if any of those is true call m_error
**to call the error.
*/
void	check_cmd(char **line)
{
	if (!ft_strncmp("echo -n ", *line, 8))
		ft_putstr_fd("echo sin salto\n", 1);
	else if (!ft_strncmp("echo", *line, 4))
		ft_putstr_fd("echo con salto\n", 1);
	else
		m_error(line);
}
