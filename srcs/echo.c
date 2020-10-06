/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 23:18:12 by mpernia-          #+#    #+#             */
/*   Updated: 2020/10/05 14:44:42 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			echo(char **line)
{
	pid_t	child = fork();
	char	**args;

	if (child == 0)
	{
		args = ft_split(*line, ' ');
		/*int  i = 0;
		while (args[i])
		{
			ft_printf("[%s]\n", args[i++]);
		}*/

		//->$PATH....echo, ls, ---> EXE
		execve ("/bin/echo", args, NULL);
	}
	else if (child > 0)
		wait(NULL);
	else
		m_error(line, UNDEFINED_ERR);
}
