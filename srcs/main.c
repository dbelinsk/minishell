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
/*
char			*test_formater(char *line, int end)
{
	char			*fmt;
	char			*tmp1;
	char			*tmp2;
	int 			i = 0;

	fmt = ft_strdup("");
	while (ft_strlen(line) > 0)
	{
		tmp1 = formater(&line, end);
		printf("tmp[%d] = [%s]\n",i++, tmp1);
		tmp2 = ft_strjoin(fmt, tmp1);
		free(fmt);
		free(tmp1);
		fmt = tmp2;
	}
	printf("formated = [%s]\n", fmt);
	if (ft_strlen(fmt) > 1)
	{
		free(fmt);
		fmt = NULL;
	}
	return (fmt);
}

int			iss_sep(char *s, char c)
{
	while (*s)
		if (*(s++) == c)
			return (1);
	return (0);
}

char			*test_type(char *line)
{
	int			end;
	int			opened;
	end = 0;
	opened = 0;
	while (line[end])
	{
		if (iss_sep("\"\'", line[end]))
			opened = 1;
		if (iss_sep(" |&;", line[end]) && !opened)
			break ;
		end++;
	}
	return (formater(&line, end));
}

*/
int main(int argc, char **argv)
{
	t_command	*cmd;
	char 		*line = NULL;

	//ft_setenv("PAPA", "echo", 1);
	//signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	cmd = NULL;
	while (1)
	{
		if (!get_cmd(&line))
			return (m_error(NULL, NULL, UNDEFINED_ERR));
		//char *fmt = test_formater(line);
		/*char *fmt = formater(&line, ft_strlen(line));
		printf("[%s]\n", fmt);
		free(fmt);*/
		init(&cmd, line);
		free(line);
		if (!execute(&cmd))
			break ;
		line = NULL;
	}
	return (0);
}
