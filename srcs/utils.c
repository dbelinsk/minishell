/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 21:19:08 by mpernia-          #+#    #+#             */
/*   Updated: 2020/10/24 21:05:24 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			put_promt()
{
	char *dir;

	dir = NULL;
	dir = getcwd(dir, 0);
	write(STDERR_FILENO, "\033[36m", 5);
	write(STDOUT_FILENO, dir, strlen(dir));
	write(STDERR_FILENO, "\033[34m", 5);
	write(STDOUT_FILENO, "\n$ ", 3);
	write(STDERR_FILENO, "\033[37m", 5);
	free(dir);
}

int			is_sep(char *s, char c)
{
	while (*s)
		if (*(s++) == c)
			return (1);
	return (0);
}

int m_error(char *type, char *content, int n)
{
	ft_putstr_fd("-bash: ", 1);
	ft_putstr_fd(type, 1);
	if (content)
	{
		ft_putstr_fd(": ", 1);
		ft_putstr_fd(content, 1);
	}
	if (n == COMMAND_ERR)
		ft_putendl_fd(": command not found.", 1);
	else if (n == MALLOC_ERR)
		ft_putstr_fd("Memory could not be allocated.\n", 1);
	else if (n == INIT_ERROR)
		ft_putendl_fd("Failed to init comandline", 1);
	else if (n == DIR_ERROR)
		ft_putendl_fd(": No such file or directory", 1);
	else if (n == IDENTIFYER_ERROR)
		ft_putendl_fd(": not a valid identifier", 1);
	else
		ft_putstr_fd("Undefined error.\n", 1);
	return(1);
}

/*int m_exit(char **to_free, t_command **cmd)
{
	free(*to_free);
	*to_free = NULL;
	return (0);
}*/
