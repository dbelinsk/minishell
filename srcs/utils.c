/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 21:19:08 by mpernia-          #+#    #+#             */
/*   Updated: 2020/10/05 13:20:11 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			put_promt()
{
	char *dir;

	dir = NULL;
	dir = getcwd(dir, 0);
	write(STDOUT_FILENO, dir, strlen(dir));
	write(STDOUT_FILENO, "\n$ ", 3);
	free(dir);
}

int m_error(char** line, int n)
{
	if (n == COMMAND_ERR)
		ft_printf("%s: command not found.\n", *line);
	else if (n == MALLOC_ERR)
		ft_putstr_fd("Memory could not be allocated.\n", 1);
	else if (n == INIT_ERROR)
		ft_putendl_fd("Failed to init comandline", 1);
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
