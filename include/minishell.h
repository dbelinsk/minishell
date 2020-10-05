#ifndef MINISHELL_H
# define MINISHELL_H
# include <get_next_line.h>
# include <libft.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>

int		get_cmd(char **line);
int		m_exit(char **to_free);
int		m_error(char **line);
void	put_promt();


void	format_cmd(char **line);
void	check_cmd(char **line);
void	echo(char **line, int n);

#endif
