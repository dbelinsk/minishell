/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:30:03 by dbelinsk          #+#    #+#             */
/*   Updated: 2020/10/02 21:32:47 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char				*gnl_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

static void				new_line(int fd, char **s, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s[fd][i] != '\n')
		i++;
	*line = gnl_substr(s[fd], 0, i);
	tmp = gnl_strdup(&s[fd][i + 1]);
	free(s[fd]);
	s[fd] = tmp;
}

static int				output(int ret, int fd, char **s, char **line)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (!s[fd] || !*(s[fd])))
	{
		*line = gnl_strdup("");
		if (s[fd])
			gnl_strdel(&s[fd]);
		return (0);
	}
	if (gnl_strchr(s[fd], '\n'))
		new_line(fd, s, line);
	else
	{
		*line = gnl_strdup(s[fd]);
		gnl_strdel(&s[fd]);
		return (0);
	}
	return (1);
}

int						get_next_line(int fd, char **line)
{
	int				ret;
	static char		*s[4096];
	char			*buff;
	char			*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	if (!(buff = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = gnl_strdup(buff);
		else
		{
			tmp = gnl_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (gnl_strchr(s[fd], '\n'))
			break ;
	}
	free(buff);
	return (output(ret, fd, s, line));
}
