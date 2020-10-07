#include "minishell.h"

/**
 ** TODO - modify parameters to recive (char **line)
 ** TODO - trim *line from whitespaces
 ** TODO - get TYPE and leave line[0] on first printable character
 ** TODO - return TYPE on success, NULL on fail
 */
char		*get_type(char **line)
{
	char		*ret;
	int			i;

	if (!*line)
		return (NULL);
	while (**line && **line == ' ')
		(*line)++;
	ret = ft_strdup(*line);
	i = -1;
	while (ret[++i])
		if (ret[i] == ' ')
		{
			ret[i] = 0;
			break ;
		}
	*line += i;
	return (ret);
}

/**
 ** TODO - modify parameters to recive (char **line)
 ** TODO - trim *line from whitespaces
 ** TODO - get CONTENT and leave line[0] on first printable character
 ** TODO - return CONTENT on success, NULL on fail
 */
char		*get_content(char **line)
{
		char		*ret;
	int			i;

	if (!*line)
		return (NULL);
	while (**line && **line == ' ')
		(*line)++;
	ret = ft_strdup(*line);
	i = -1;
	while (ret[++i])
		if (ret[i] == '|' || ret[i] == ';')
		{
			ret[i] = 0;
			break ;
		}
	*line += i;
	return (ret);
}

/**
 ** TODO - modify parameters to recive (char **line)
 ** TODO - trim *line from whitespaces
 ** TODO - get FLAGS and leave line[0] on first printable character
 ** TODO - return 1 if FLAG found, 0 no FLAG, -1 on fail
 */
int			get_flag(char **line)
{
	if (!*line)
		return (-1);
	while (**line && **line == ' ')
		(*line)++;
	if (!ft_strncmp(*line, "-n", 2))
	{
		(*line) += 2;
		return (1);
	}
	return (NONE);
}

/**
 ** TODO - modify parameters to recive (char **line)
 ** TODO - trim *line from whitespaces
 ** TODO - get SEPARATOR and leave line[0] on first printable character
 **			if exists
 ** TODO - return 2 on PIPE found, 1 on NEW CMD, 0 no SEP, -1 on fail
  */
int			get_sep(char **line)
{
	int		ret;

	ret = NONE;
	if (!*line)
		return (-1);
	while (**line && **line == ' ')
		(*line)++;
	if (!ft_strncmp(*line, ";", 1))
		ret = SEMCOL;
	else if (!ft_strncmp(*line, "|", 1))
		ret = PIPE;
	if(ret)
		(*line)++;
	return (ret);
}

/**
 ** TODO - modify parameters to recive (char *type)
 ** TODO - get PATH based on recived type
 ** TODO - return PATH on success, NULL on fail
 */
char		*get_path(char *type, char *paths)
{
	char			**path_arr;
	struct stat		fileStat;
	char			*full_path;
	char			*tmp;
	char			*ret;

	paths += 5;
	path_arr = ft_split(paths, ':');
	ret = NULL;
	while (*path_arr)
	{
		tmp = ft_strjoin(*path_arr, "/");
		full_path = ft_strjoin(tmp, type);
		if (stat(full_path, &fileStat) == 0)
			if (fileStat.st_size > 0 && !ret)
				ret = ft_strdup(full_path);
		free(*path_arr);
		free(tmp);
		free(full_path);
		path_arr++;
	}
	return (ret);
}

/**
 ** TODO - modify parameters to recive (char *type)
 ** TODO - get EXECUTABLE function based on recived cmd (or type)
 ** TODO - return EXECUTABLE function on success, NULL on fail
 */
void		*get_exe(char *type)
{
	return (&execute);
}
