/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 23:18:12 by mpernia-          #+#    #+#             */
/*   Updated: 2020/10/02 23:57:43 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char**	argument_builder(char** line, int n)
{
	char** output;

	if (!(output = (char**)ft_calloc(n + 3, sizeof(char**))))
		return (NULL);
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

void			echo(char **line, int n)
{
	pid_t	child = fork();
	char**	args;

	if (child == 0)
	{
		args = argument_builder(line, n);
		execve ("/bin/echo", args, NULL);
	}
	else if (child > 0)
		wait(NULL);
	else
		ft_putstr_fd("error\n", 1);
}
