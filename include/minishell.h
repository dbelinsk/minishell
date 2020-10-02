#ifndef MINISHELL_H
# define MINISHELL_H
# include <get_next_line.h>
# include <libft.h>

int		get_cmd(char **line);
int		m_exit(char **to_free);
int		m_error(char **line);

void	format_cmd(char **line);
void	check_cmd(char **line);

#endif
