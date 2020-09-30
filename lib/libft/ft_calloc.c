/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 12:56:46 by dbelinsk          #+#    #+#             */
/*   Updated: 2019/11/20 12:47:25 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	void		*ptr;

	if (!(ptr = malloc(size * count)))
		return (NULL);
	return (ft_memset(ptr, '\0', (size * count)));
}
