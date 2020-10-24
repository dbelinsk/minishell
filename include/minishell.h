#ifndef MINISHELL_H
# define MINISHELL_H

# define COMMAND_ERR 		0
# define MALLOC_ERR 		1
# define UNDEFINED_ERR 		2
# define INIT_ERROR 		3
# define DIR_ERROR 			4
# define IDENTIFYER_ERROR 	5

# include <get_next_line.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <printf.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <dirent.h>
# include <errno.h>
# include <libft.h>
# include <stdio.h>

# define NONE					0
# define SEMCOL					1
# define PIPE					2
# define AND					3
# define REDIRECTION_READ		1
# define REDIRECTION_WRITE		2
# define REDIRECTION_APPEND		3

typedef struct 		s_command
{
	char				*type;
	char				*path;
	char				*content;
	char				*flag;
	char				*fname;
	char				sep;
	int					redirection;
	int					err;
	int					(*exe)();
	struct s_command	*next;
	struct s_command	*prev;
}					t_command;

void	put_promt(void);
void	*get_exe(char *type);
void	clean_cmd(t_command **cmd);
void	universal(t_command *cmd);
void	redirect(t_command *cmd, char *content);

int		get_sep(char **line);
int		get_cmd(char **line);
int		s_cd(t_command *cmd);
int		s_pwd(t_command *cmd);
int		s_env(t_command *cmd);
int		s_exit(t_command *cmd);
int		s_echo(t_command *cmd);
int		s_unset(t_command *cmd);
int		is_sep(char *s, char c);
int		s_export(t_command *cmd);
int		execute(t_command **cmd);
int		get_redirection(char **line);
int		ft_unsetenv(const char *name);
int		init(t_command **cmd, char *line);
//int		m_exit(char **to_free, t_command **cmd); Not using right now
int		m_error(char *type, char *content, int n);
int		formater_env_handler(char **line, char *aux, int *x, char q);
int		ft_setenv(const char *name, const char *value, int overwrite);

char	*get_type(char **line);
char	*get_flag(char **line);
char	*get_content(char **line);
char	*ft_getenv(const char *var);
char	*get_path(char *type, char *paths);
char	*bslash_quote_formater(char **line, int end);

#endif
