/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 21:19:08 by mpernia-          #+#    #+#             */
/*   Updated: 2020/10/04 15:29:44 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int m_error(char** line, int n)
{
	if (n == COMMAND_ERR)
	{
		*line = ft_strjoin(*line, ": command not found.\n");
		ft_putstr_fd(*line, 1);
	}
	else if (n == MALLOC_ERR)
		ft_putstr_fd("Memory could not be allocated.\n", 1);
	else
		ft_putstr_fd("Undefined error.\n", 1);
	return(1);
}

int m_exit(char **to_free)
{
	free(*to_free);
	*to_free = NULL;
	return (0);
}
