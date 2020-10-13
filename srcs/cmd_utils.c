#include "minishell.h"

void	backslash_remover(char **line, char **ret, int *i, int *j)
{
	(*i)++;
	*(*ret + (*j)++) = *(*line + (*i)++);
}

void 	quapo_remover(char **line, char **ret, int *i, int *j)
{
	char	quapo;
	int		quapo_found;

	quapo = *(*line + *i);
	(*i)++;
	quapo_found = 0;
	while (*(*line + *i) && quapo_found < 1)
	{
		if (*(*line + *i) == '\\')
			backslash_remover(line, ret, i, j);
		else if (*(*line + *i) == quapo)
		{
			quapo_found = 1;
			(*i)++;
		}
		else
			*(*ret + (*j)++) = *(*line + (*i)++);
	}
	if (quapo_found == 0)
		ft_printf("error, amigo.");
}

int		flag_checker(char **ret)
{
	char *aux;

	if (!ft_strncmp(*ret, "-n ", 3))
	{
		aux = ft_strdup(*ret + 3);
		//free(*ret);
		*ret = aux;
		//free(aux);
		return 1;
	}
	return 0;
}

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
	int i;
	int j;
	char *ret;

	if (!*line)
		return(NULL);
	i = 0;
	while(*(*line + i) && *(*line + i) == ' ')
		i++;
	ret = ft_calloc(ft_strlen(*line + i), sizeof(char));
	j = 0;
	while (*(*line + i) && *(*line + i) != ' ')
	{

		if (*(*line + i) == '\\')
			backslash_remover(line, &ret, &i, &j);
		else if (*(*line + i) == '\'' || *(*line + i) == '\"')
			quapo_remover(line, &ret, &i, &j);
		else
			*(ret + j++) = *(*line + i++);
		/*if ((ret[i] == ' ' && ret[i - 1] != '\\')
			|| is_sep("|;&", ret[i]))
		{
			ret[i] = 0;
			break ;
		}*/
	}
	*line += i;
	return(ret);
}

/*
** Functions cleans all spaces from the front of the string, stores in the
** variable to be returned x characters until \0 | or ; is found and moves
** a pointer of parameter resived x positions;
** @param line pointer to memory of the string
** @return pointer to memory reservated string that represents a content
**			NULL on fail
*/
char		*get_content(char **line, int *flag)
{
	int i;
	int j;
	char *ret;

	if (!*line)
		return(NULL);
	i = 0;
	while(*(*line + i) && *(*line + i) == ' ')
		i++;
	ret = ft_calloc(ft_strlen(*line + i), sizeof(char));
	j = 0;
	while (*(*line + i) && (*(*line + i) != '|' || *(*line + i) != ';'))
	{
		if (*(*line + i) == '\\')
			backslash_remover(line, &ret, &i, &j);
		else if (*(*line + i) == '\'' || *(*line + i) == '\"')
			quapo_remover(line, &ret, &i, &j);
		else if (*(*line + i) == ' ' && *(*line + i + 1) == ' ')
			i++;
		else
			*(ret + j++) = *(*line + i++);
		/*if (is_sep(";|&", ret[j]) && ret[j - 1] != '\\')
		{
			ret[i] = 0;
			break ;
		}*/
	}
	/*i = -1;
	while (ret[++i])
	{
		if (is_sep(";|&", ret[i]) && ret[i - 1] != '\\')
		{
			ret[i] = 0;
			break ;
		}
	}*/
	*line += i;
	*flag = flag_checker(&ret);
	return(ret);
}

/**
** Functions cleans all spaces from the front of the string and moves
** a pointer of parameter resived x positions;
** @param line pointer to memory of the string
** @return 1 if flag found, 0 if flag not found and -1 on fail

int			get_flag(char **line)
{
	int i;

	i = 0;
	if (!*line)
		return (-1);
	while (**line && **line == ' ')
		(*line)++;
	if (!ft_strncmp(*line, "-n ", 3))
		i = 3;
	else if (!ft_strncmp(*line, "\\-n ", 4) || !ft_strncmp(*line, "-\\n ", 4))
		i = 4;
	else if (!ft_strncmp(*line, "\\-\\n ", 5))
		i = 5;
	(*line) += i;
	if (i > 0)
		return(1);
	return(i);
}
*/

/**ech
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
	else if (!ft_strncmp(*line, "&&", 2))
	{
		(*line)++;
		ret = AND;
	}
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
	struct stat		filestat;
	char			*full_path;
	char			*tmp;
	int				i;

	paths += 5;
	path_arr = ft_split(paths, ':');
	i = 0;
	while (path_arr[i])
	{
		tmp = ft_strjoin(path_arr[i], "/");
		full_path = ft_strjoin(tmp, type);
		free(tmp);
		if (stat(full_path, &filestat) == 0)
			if (filestat.st_size > 0 && ft_isalpha(*type))
				break ;
		free(path_arr[i++]);
		free(full_path);
		full_path = NULL;
	}
	while (path_arr[i])
		free(path_arr[i++]);
	free(path_arr);
	return (full_path);
}

/**
 ** TODO - modify parameters to recive (char *type)
 ** TODO - get EXECUTABLE function based on recived cmd (or type)
 ** TODO - return EXECUTABLE function on success, NULL on fail
 */
void		*get_exe(char *type)
{
	int		len;

	len = ft_strlen(type);
	if (!ft_strncmp(type, "exit", len))
		return (&s_exit);
	if (!ft_strncmp(type, "echo", len))
		return (&s_echo);
	if (!ft_strncmp(type, "cd", len))
		return (&s_cd);
	if (!ft_strncmp(type, "pwd", len))
		return (&s_pwd);
	if (!ft_strncmp(type, "env", len))
		return (&s_env);
	if (!ft_strncmp(type, "export", len))
		return (&s_export);
	if (!ft_strncmp(type, "unset", len))
		return (&s_unset);
	return (NULL);
}
