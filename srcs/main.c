/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 21:19:01 by mpernia-          #+#    #+#             */
/*   Updated: 2020/10/02 23:45:05 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, "\033[2D\033[J\n", 10);
		write(STDOUT_FILENO, "\033[1D", 4);
		put_promt();
	}
	if (sig == SIGQUIT)
		write(STDOUT_FILENO, "\033[2D\033[J", 7);
}

int main(void)
{
	char *line = NULL;

	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	while (1)
	{
		if (!get_cmd(&line))
			return (m_error(&line));
		if (!ft_strncmp("exit", line, 4))
			return (m_exit(&line));
		format_cmd(&line);
		check_cmd(&line);
		free(line);
		line = NULL;
	}
	return (0);
}
