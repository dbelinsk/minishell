/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:15:34 by dbelinsk          #+#    #+#             */
/*   Updated: 2019/11/25 18:43:14 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *hayst, const char *ndl, size_t len)
{
	size_t		n_len;

	if (!*ndl)
		return ((char*)hayst);
	if (len == 0 || !*hayst)
		return (NULL);
	n_len = ft_strlen(ndl);
	while (len >= n_len && *hayst)
	{
		if (ft_strncmp(hayst, ndl, n_len) == 0)
			return ((char*)hayst);
		hayst++;
		len--;
	}
	return (NULL);
}
