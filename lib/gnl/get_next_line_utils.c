/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:31:44 by dbelinsk          #+#    #+#             */
/*   Updated: 2019/11/27 18:36:45 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t				ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void				ft_strdel(char **str)
{
	if (str != NULL && *str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	if (s)
	{
		if (!(str = malloc(((int)len + 1) * sizeof(char))))
			return (NULL);
		i = 0;
		if (start <= ft_strlen(s))
		{
			while (i < len && s[i])
			{
				str[i] = s[i + start];
				i++;
			}
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

char				*ft_strdup(const char *s)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	size = ft_strlen(s);
	if (!(str = (char*)malloc(sizeof(*str) * size + 1)))
		return (NULL);
	while (i < size)
	{
		str[i] = s[i];
		i++;
	}
	str[size] = '\0';
	return (str);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = 0;
	if (s1 && s2)
	{
		if (!(str = (char*)malloc((ft_strlen(s1) +
							ft_strlen(s2) + 1) * sizeof(char))))
			return (NULL);
		while (*s1)
			str[i++] = *s1++;
		while (*s2)
			str[i++] = *s2++;
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
