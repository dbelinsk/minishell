/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 21:19:08 by mpernia-          #+#    #+#             */
/*   Updated: 2020/10/02 22:39:57 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int m_error(char** line)
{
	*line = ft_strjoin(*line, ": command not found\n");
	ft_putstr_fd(*line, 1);
	return(1);
}

int m_exit(char **to_free)
{
	free(*to_free);
	*to_free = NULL;
	return (0);
}