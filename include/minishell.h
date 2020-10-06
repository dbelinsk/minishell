#ifndef MINISHELL_H
# define MINISHELL_H

# define COMMAND_ERR 0
# define MALLOC_ERR 1
# define UNDEFINED_ERR 2
# define INIT_ERROR 3

# include <get_next_line.h>
# include <libft.h>
# include <printf.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# define NONE		0
# define COL		1
# define SEMCOL		2
# define NL			3


typedef struct 		s_command
{
	char				*type;
	char				*path;
	char				*content;
	int					flag;		// 0 o 1
	int					sep;
	void				(*exe)();
	struct s_command	*next;
}					t_command;

int		init(t_command **cmd, char *line);
int		execute(t_command cmd);

int		get_cmd(char **line);
int		m_exit(char **to_free);
int		m_error(char **line, int n);
void	put_promt();

void	format_cmd(char **line);
void	check_cmd(char **line);
void	echo(char **line);

char		*get_type();
char		*get_path();
char		*get_content();
int			get_flag();
int			get_sep();
void		*get_exe(t_command cmd);


#endif
