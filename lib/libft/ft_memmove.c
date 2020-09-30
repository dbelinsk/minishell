/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:43:30 by dbelinsk          #+#    #+#             */
/*   Updated: 2019/11/25 14:53:03 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	if (len == 0 || dst == src)
		return (dst);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	while (len--)
		((unsigned char *)dst)[len] = ((unsigned const char *)src)[len];
	return (dst);
}
