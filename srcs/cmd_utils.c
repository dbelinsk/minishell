#include "minishell.h"

/*
** Functions cleans all spaces from the front of the string, finds position
** until next space[ ], pipe[|], and[&], semicolin[;].
** @param line = original string to modify
** @return pointer to memory reservated string that represents a type
**			NULL on fail
*/

char		*get_type(char **line)
{
	int			end;
	int			opened;
	char		q;

	end = 0;
	opened = 0;
	q = 0;
	while (**line && is_sep(" ", **line))
		*line += 1;
	while ((*line)[end])
	{
		if (is_sep("\"\'", (*line)[end]))
		{
			if (!q)
				q = (*line)[end];
			if (q == (*line)[end])
				opened++;
		}
		if (opened == 2)
			opened = 0;
		if (is_sep(" |&;<>", (*line)[end]) && !opened)
			break ;
		end++;
	}
	return (bslash_quote_formater(line, end));
}

/*
** Functions cleans all spaces from the front of the string, finds position
** until next pipe[|], and[&], semicolin[;].
** @param line = original string to modify
** @return pointer to memory reservated string that represents a type
**			NULL on fail
*/

char		*get_content(char **line)
{
	int				opened;
	char			q;
	int 			end;

	end = 0;
	opened = 0;
	q = 0;
	while (**line && is_sep(" ", **line))
		*line += 1;
	while ((*line)[end])
	{
		if (is_sep("\'\"", (*line)[end]))
		{
			if (!q)
				q = (*line)[end];
			if (q == (*line)[end])
				opened++;
		}
		if (opened == 2)
			opened = 0;
		if (is_sep("|&;<>", (*line)[end]) && !opened)
			break ;
		end++;
	}
	while ((*line)[end - 1] && (*line)[end - 1] == ' ')
		end--;
	return (bslash_quote_formater(line, end));
}

/*
** Functions cleans all spaces from the front of the string and moves
** a pointer of parameter resived x positions;
** @param line pointer to memory of the string
** @return 1 if flag found, 0 if flag not found and -1 on fail
*/

char			*get_flag(char **line)
{
	char		*fmt;
	int			end;
	int			opened;
	char		*flag;
	char		q;

	end = 0;
	opened = 0;
	flag = NULL;
	q = 0;
	while (**line && is_sep(" ", **line))
		*line += 1;
	while ((*line)[end])
	{
		if (is_sep("\"\'", (*line)[end]))
		{
			if (!q)
				q = (*line)[end];
			if (q == (*line)[end])
				opened++;
		}
		if (opened == 2)
			opened = 0;
		if (is_sep(" |&;<>", (*line)[end]) && !opened && (*line)[end - 1] != '\\')
			break ;
		end++;
	}
	fmt = bslash_quote_formater(line, end);
	if (!ft_strncmp(fmt, "-n", 2) && ft_strlen(fmt) == 2)
		flag = ft_strdup("-n");
	else
	{
		flag = ft_strdup("");
		*line -= end;
	}
	free(fmt);
	return (flag);
}

int			get_redirection(char **line)
{
	int		ret;

	ret = NONE;
	if (!*line)
		return (-1);
	while (**line && **line == ' ')
		(*line)++;
	if (!ft_strncmp(*line, "<", 1))
		ret = REDIRECTION_READ;
	else if (!ft_strncmp(*line, ">>", 2))
	{
		(*line)++;
		ret = REDIRECTION_APPEND;
	}
	else if (!ft_strncmp(*line, ">", 1))
		ret = REDIRECTION_WRITE;
	if(ret)
		(*line)++;
	return (ret);
}

/*
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
	while (**line && **line == ' ')
		(*line)++;
	if (**line == ';')
	{
		printf("syntax error\n");
		return (-1);
	}
	return (ret);
}

/*
** Function
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
	else if (!ft_strncmp(type, "echo", len))
		return (&s_echo);
	else if (!ft_strncmp(type, "cd", len))
		return (&s_cd);
	else if (!ft_strncmp(type, "pwd", len))
		return (&s_pwd);
	//else if (!ft_strncmp(type, "env", len))
	//	return (&s_env);
	else if (!ft_strncmp(type, "export", len))
		return (&s_export);
	else if (!ft_strncmp(type, "unset", len))
		return (&s_unset);
	else
		return (&universal);

	//TODO else universal
	return (NULL);
}
