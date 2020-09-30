/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:54:38 by dbelinsk          #+#    #+#             */
/*   Updated: 2019/11/25 14:32:27 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memset(void *b, int c, size_t len)
{
	size_t							count;
	unsigned char					*str;

	count = 0;
	str = (unsigned char*)b;
	while (count < len)
	{
		str[count] = (unsigned char)c;
		count++;
	}
	return (b);
}
