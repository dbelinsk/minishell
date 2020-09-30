/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:01:41 by dbelinsk          #+#    #+#             */
/*   Updated: 2019/11/20 12:51:19 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*get_frag(const char *s, int c)
{
	char		*sep;
	char		*frag;

	if (!(sep = (char*)malloc(sizeof(*sep) + 1)))
		return (NULL);
	sep = (char*)ft_memset(sep, c, 1);
	if (!(frag = ft_strtrim(s, sep)))
		return (NULL);
	free(sep);
	return (frag);
}

static size_t		get_frag_size(const char *s, int c)
{
	size_t		size;

	size = 0;
	while (s[size] && s[size] != c)
		size++;
	return (size);
}

static size_t		get_arr_size(char *str, char c)
{
	size_t		count;
	int			i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (0);
	count = 1;
	while (str[i])
	{
		if (str[i] == c)
		{
			count++;
			while (str[i] && str[i] == c)
				i++;
		}
		i++;
	}
	return (count);
}

static char			**set_arr(char *str, int count, char c)
{
	char		**arr;
	char		*tmp;
	int			i;
	int			f_size;

	if (!(arr = (char**)malloc(sizeof(char**) * (count + 1))))
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*str && *str == c)
			str++;
		f_size = get_frag_size(str, c);
		if (!(tmp = (char*)ft_calloc(f_size + 1, sizeof(*tmp))))
			return (NULL);
		tmp = ft_strncpy(tmp, str, f_size);
		str = ft_memccpy(str, str, c, ft_strlen(str));
		arr[i] = tmp;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char				**ft_split(char const *s, char c)
{
	char		**arr;
	char		*str;
	int			count;

	if (!s)
		return (NULL);
	if (!(str = get_frag(s, c)))
		return (NULL);
	count = get_arr_size(str, c);
	if (!(arr = set_arr(str, count, c)))
		return (NULL);
	free(str);
	return (arr);
}
