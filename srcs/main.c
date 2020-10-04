/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 21:19:01 by mpernia-          #+#    #+#             */
/*   Updated: 2020/10/04 15:23:38 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
	char *line = NULL;
	while (1)
	{
		if (!get_cmd(&line))
			return (m_error(&line, UNDEFINED_ERR));
		if (!ft_strncmp("exit", line, 4))
			return (m_exit(&line));
		format_cmd(&line);
		check_cmd(&line);
/*		ft_putstr_fd("[",1);
		ft_putstr_fd(line, 1);
		ft_putstr_fd("]\n",1);*/
		free(line);
		line = NULL;
	}
	return (0);
}
