/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 21:19:01 by mpernia-          #+#    #+#             */
/*   Updated: 2020/10/08 00:30:04 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, "\033[2D\033[J\n", 10);
		put_promt();
	}
	if (sig == SIGQUIT)
		write(STDOUT_FILENO, "\033[2D\033[J", 7);
}

int main(int argc, char **argv, char **envp)
{
	t_command	*cmd;
	char 		*line = NULL;

	ft_setenv("PAPA", "Mario", 1);
	//signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	cmd = NULL;
	while (1)
	{
		if (!get_cmd(&line))
			return (m_error(NULL, NULL, UNDEFINED_ERR));
		if (init(&cmd, line) < 0)
			continue ;
		free(line);
		if (!execute(&cmd))
			break ;
		line = NULL;
	}
	return (0);
}
