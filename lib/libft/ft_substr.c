/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:00:13 by dbelinsk          #+#    #+#             */
/*   Updated: 2019/11/20 12:54:49 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	void	*str;

	if (!s || !(str = ft_calloc(len + 1, sizeof(*str))))
		return (NULL);
	if (ft_strlen(s) < (size_t)start)
		return (str);
	return ((char*)ft_memcpy(str, s + start, len));
}
