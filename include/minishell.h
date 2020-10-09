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
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# define NONE		0
# define SEMCOL		1
# define PIPE		2

typedef struct 		s_command
{
	char				*type;
	char				*path;
	char				*content;
	int					flag;		// 0 o 1
	int					sep;
	int					(*exe)();
	struct s_command	*next;
}					t_command;

void	put_promt();
void	echo(char **line);
void	*get_exe(char *type);
void	check_cmd(char **line);
void	format_cmd(char **line);
void	init(t_command **cmd, char *line, char *paths);

int		get_sep(char **line);
int		get_cmd(char **line);
int		get_flag(char **line);
int		m_exit(char **to_free, t_command **cmd);
int		execute(t_command **cmd);
int		m_error(char **line, int n);

char	*get_type(char **line);
char	*get_content(char **line);
char	*backslash_remover(char *type);
char	*get_path(char *type, char *paths);

void		clean_cmd(t_command **cmd);
int				s_exit(t_command **cmd);
int				s_echo(t_command **cmd);


#endif
