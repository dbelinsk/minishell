#include "minishell.h"

/**
** Functions cleans all spaces from the front of the string, stores x
** characters until next space in the variable to be returned and moves
** a pointer of parameter resived x positions;
** @param line pointer to memory of the string
** @return pointer to memory reservated string that represents a type
**			NULL on fail
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
** Functions cleans all spaces from the front of the string, stores in the
** variable to be returned x characters until \0 | or ; is found and moves
** a pointer of parameter resived x positions;
** @param line pointer to memory of the string
** @return pointer to memory reservated string that represents a content
**			NULL on fail
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
** Functions cleans all spaces from the front of the string and moves
** a pointer of parameter resived x positions;
** @param line pointer to memory of the string
** @return 1 if flag found, 0 if flag not found and -1 on fail
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
** Functions cleans all spaces from the front of the string and moves
** a pointer of parameter resived x positions;
** @param line pointer to memory of the string
** @return 2 if pipe separator found, 1 if comma separator found, 0 if
** no separator found and -1 on fail
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
** Functions
** @param type executable to find
** @param line all pathes to executable available on mashine
** @return pointer to memory reservated string that represents a full path
**			of executable, NULL on fail
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
