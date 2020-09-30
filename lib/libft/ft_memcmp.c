/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:45:10 by dbelinsk          #+#    #+#             */
/*   Updated: 2019/11/25 16:57:31 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int				ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*p1;
	unsigned char		*p2;
	size_t				i;

	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	i = -1;
	while (++i < n)
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
	return (0);
}
