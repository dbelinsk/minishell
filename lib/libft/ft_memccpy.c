/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:41:59 by dbelinsk          #+#    #+#             */
/*   Updated: 2019/11/20 12:49:16 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned const char		*p_src;
	unsigned char			*p_dst;
	size_t					i;

	p_src = (unsigned char*)src;
	p_dst = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		p_dst[i] = p_src[i];
		if (p_dst[i] == (unsigned char)c)
			return ((void*)dst + (i + 1));
		i++;
	}
	return (NULL);
}
