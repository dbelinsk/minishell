/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 23:18:12 by mpernia-          #+#    #+#             */
/*   Updated: 2020/10/04 15:25:32 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char**	argument_builder(char** line, int n)
{
	char** output;

	if (!(output = (char**)ft_calloc(n + 3, sizeof(char**))))
		m_error(line, MALLOC_ERR);
	if (n == 0)
	{
		output[0] = ft_strdup("echo");
		if (ft_strlen(*line) > 5)
			output[1] = ft_strdup(*line + 5);
		else
			output[1] = ft_strdup("");
	}
	else
	{
		output[0] = ft_strdup("echo");
		output[1] = ft_strdup("-n");
		if (ft_strlen(*line) > 7)
			output[2] = ft_strdup(*line + 8);
		else
			output[2] = ft_strdup("");
	}
	return(output);
}

void			echo(char **line)
{
	pid_t	child = fork();
	char**	args;
	int n;

	n = 0;
	if (!ft_strncmp("echo -n ", *line, 8))
		n = 1;
	if (child == 0)
	{
		args = argument_builder(line, n);
		execve ("/bin/echo", args, NULL);
	}
	else if (child > 0)
		wait(NULL);
	else
		m_error(line, UNDEFINED_ERR);
}
