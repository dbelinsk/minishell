#ifndef MINISHELL_H
# define MINISHELL_H

# define COMMAND_ERR 0
# define MALLOC_ERR 1
# define UNDEFINED_ERR 2

# include <get_next_line.h>
# include <libft.h>
# include <printf.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>

int		get_cmd(char **line);
int		m_exit(char **to_free);
int		m_error(char **line, int n);

void	format_cmd(char **line);
void	check_cmd(char **line);
void	echo(char **line);

#endif
