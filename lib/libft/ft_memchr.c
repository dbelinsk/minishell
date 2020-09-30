/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:44:34 by dbelinsk          #+#    #+#             */
/*   Updated: 2019/11/25 15:09:04 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if ((unsigned char)c == *(unsigned char*)s)
			return ((unsigned char*)s);
		s++;
	}
	return (NULL);
}
