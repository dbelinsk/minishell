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

typedef struct s_content
{
	char				*content;
	struct s_content	*next;
}				t_content;


typedef struct s_command
{
	char				*type;
	int					flag;		// 0 o 1
	char				*path;
	t_content			*content;
	void				(*exe)();
	struct s_comand		*next;
}				t_command;

int		get_cmd(char **line);
int		m_exit(char **to_free);
int		m_error(char **line, int n);
void	put_promt();

void	format_cmd(char **line);
void	check_cmd(char **line);
void	echo(char **line);

#endif
