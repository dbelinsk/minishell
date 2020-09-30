/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:01:10 by dbelinsk          #+#    #+#             */
/*   Updated: 2019/11/20 12:54:35 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	char		*aux;
	size_t		st_len;
	size_t		len;

	if (!s1 || !set)
		return (0);
	st_len = ft_strlen(set);
	aux = (char*)s1;
	while (*aux && ft_memchr(set, *aux, st_len))
		aux++;
	len = ft_strlen(aux);
	if (len > 0)
		while (aux[len - 1] && ft_memchr(set, aux[len - 1], st_len))
			len--;
	if (!(str = ft_calloc(len + 1, sizeof(*str))))
		return (NULL);
	str = ft_memcpy(str, aux, len);
	return (str);
}
