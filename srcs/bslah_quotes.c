#include "minishell.h"

/*
** Applies back slash behavior
** @param line = original string to modify
** @param fmt = string where to concatenate formated characters
** @param pos = position register for fmt
** @param q = current opened quote register
** @return 1 if parent function needs continue 0 if not
*/

static int	bck_slash_handler(char **line, char *fmt, int *pos, char q)
{
	char	*tmp;
	int		i;
	int		ret;

	tmp = *line;
	i = *pos;
	ret = 0;
	if (*(tmp + 1) && *(tmp + 1) == q)
	{
		tmp++;
		fmt[i++] = *tmp;
		tmp++;
		ret = 1;
	}
	else if (*(tmp + 1) && *(tmp + 1) == '\\' && q == '\"')
		tmp++;
	else if (*(tmp + 1) && *(tmp + 1) != '$')
		fmt[i++] = *(tmp++);
	*pos = i;
	*line = tmp;
	return (ret);
}

/*
** Applies single and double quote behavior
** @param line = original string to modify
** @param q = current opened quote register
** @param opened = opened quote register 0 = no quote opened
** 										1 = quote opened
**										2 = quete closed
** @return 1 if parent function needs continue 0 if not
*/

static int	quote_handler(char **line, char *q, int *opened)
{
	char	*tmp;
	int		ret;

	ret = 0;
	tmp = *line;
	if (*(tmp + 1) && (*(tmp + 1) == '\"' || *(tmp + 1) == '\''))
		tmp++;
	if (!*q)
		*q = *tmp;
	if (*q == *tmp)
	{
		(*opened)++;
		tmp++;
	}
	if (*opened == 2)
	{
		*opened = 0;
		*q = 0;
		ret = 1;
	}
	if (*tmp && *tmp == '\\' && *q != '\'')
		ret = 1;
	*line = tmp;
	return (ret);
}

/*
**  --- HELPER FUNCRION FOR do_format(...) ---
** Inits variables
*/

static void	init_variables(char **line, char **tmp, int *i, char *q)
{
	*tmp = *line;
	*i = 0;
	*q = 0;
}

/*
**  --- HELPER FUNCRION FOR bslash_quote_formater(...) ---
** Applies backslash [\], sinngle quote ['], double quote ["] and
** dollar [$] behavior until desired position
** @param line = original string to modify
** @param fmt = string where to concatenate formated characters
** @param opened = quote register
** @param end = position where to stop
*/

static void	do_format(char **line, char *fmt, int *opened, int end)
{
	char	*tmp;
	int		i;
	char	q;

	init_variables(line, &tmp, &i, &q);
	while (*tmp && (int)(tmp - (*line)) < end)
	{
		if (*tmp == '\\')
		{
			if (*opened)
			{
				if (bck_slash_handler(&tmp, fmt, &i, q))
					continue ;
			}
			else
				tmp++;
		}
		else if (*tmp == '\"' || *tmp == '\'')
			if (quote_handler(&tmp, &q, opened))
				continue ;
		if (formater_env_handler(&tmp, fmt, &i, q))
			continue ;
		*tmp ? (fmt[i++] = *(tmp++)) : 0;
	}
	*line = tmp;
}

/*
** Applies backslash [\], sinngle quote ['], double quote ["] and
** dollar [$] behavior until desired position
** @param line = original string to modify
** @param end = position where to stop
** @return string with \"'$ behaivior applied on it
*/

char		*bslash_quote_formater(char **line, int end)
{
	char	fmt[BUFSIZ];
	int		opened;

	opened = 0;
	ft_bzero(fmt, BUFSIZ);
	do_format(line, fmt, &opened, end);
	return (ft_strdup(fmt));
}
