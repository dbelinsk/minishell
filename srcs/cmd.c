/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 21:19:13 by mpernia-          #+#    #+#             */
/*   Updated: 2020/10/24 21:24:36 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**Prompt from cmd, it waits for command and print dir by using getcwd()
*/
int	get_cmd(char **line)
{
	put_promt();
	if (get_next_line(1, line) < 0)
		return (0);
	return (1);
}
