#include "minishell.h"

/*
** Applies back slash + dollar signd and/or quote behavior
** @param line = original string to modify
** @param fmt = string where to concatenate formated characters
** @param pos = position register for fmt
** @param q = current opened quote register
** @return 1 if parent function needs continue 0 if not
*/

int				bckslash_handler(char **line, char *fmt, int *pos, char q)
{
	int		j;

	j = *pos;
	if (**line == '\\')
	{
		if (!q)
			fmt[j++] = '$';
		else if (q == '\'')
			fmt[j++] = '$';
		else if (q == '\"')
			fmt[j - 1] = '$';
		*pos = j;
		*line += 2;
		return (1);
	}
	return (0);
}

/*
** Appends to fmt errno variable if exists
** @param line = original string to modify
** @param fmt = string where to concatenate formated characters
** @param pos = position register for fmt
** @param q = current opened quote register
** @return 1 if parent function needs continue 0 if not
*/

int				errno_handler(char **line, char *fmt, int *pos, char q)
{
	char		*env;
	int			i;
	int			j;

	j = *pos;
	i = 0;
	if (**line == '?')
	{
		env = ft_itoa(errno);
		while (env[i])
			fmt[j++] = env[i++];
		free(env);
		*pos = j;
		*line += 1;
		return (1);
	}
	return (0);
}

/*
** Appends to fmt enviroment variable if exists
** @param line = original string to modify
** @param fmt = string where to concatenate formated characters
** @param pos = position register for fmt
*/

void			get_env_handler(char **line, char *fmt, int *pos)
{
	char		name[BUFSIZ];
	char		*env;
	int			i;
	int			j;

	ft_bzero(name, BUFSIZ);
	j = *pos;
	i = 0;
	while (**line && ft_isalpha(**line))
	{
		name[i++] = **line;
		*line += 1;
	}
	if (!(env = ft_getenv(name)))
	{
		if (**line != '\"')
			*line += 1;
		return ;
	}
	while (*env)
		fmt[j++] = *(env)++;
	*pos = j;
}

/*
**  --- HELPER FUNCRION FOR formater_env_handler(...) ---
** Applies dollar sign behavior
** @param line = original string to modify
** @param fmt = string where to concatenate formated characters
** @param pos = position register for fmt
** @param q = current opened quote register
*/

void			put_env(char **line, char *aux, int *i, char q)
{
	char		*env;
	int			j;

	j = *i;
	if (bckslash_handler(line, aux, i, q))
		return ;
	*line += 2;
	if (errno_handler(line, aux, i, q))
		return ;
	if (q == '\'')
	{
		aux[j++] = '$';
		*i = j;
		return ;
	}
	get_env_handler(line, aux, i);
}

/*
** Applies dollar sign behavior
** @param line = original string to modify
** @param fmt = string where to concatenate formated characters
** @param pos = position register for fmt
** @param q = current opened quote register
** @return 1 if parent function needs continue 0 if not
*/

int				formater_env_handler(char **line, char *fmt, int *pos, char q)
{
	int			ret;
	char		*tmp;

	ret = 0;
	tmp = *line;
	if (*tmp == '$')
	{
		if (ft_strlen(tmp) - 1 > 0)
			tmp--;
		put_env(&tmp, fmt, pos, q);
		ret = 1;
	}
	*line = tmp;
	return (ret);
}
