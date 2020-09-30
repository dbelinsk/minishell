/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:20:58 by dbelinsk          #+#    #+#             */
/*   Updated: 2019/11/25 18:38:37 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		s_len;

	if (!src || !dst)
		return (0);
	s_len = ft_strlen(src);
	if (dstsize == 0)
		return (s_len);
	while (--dstsize && *src)
		*(dst++) = *(src++);
	*(dst++) = '\0';
	return (s_len);
}
