/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:02:06 by dbelinsk          #+#    #+#             */
/*   Updated: 2019/11/20 12:48:53 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				get_div(int n)
{
	unsigned int	nb;
	int				i;

	nb = n;
	if (n < 0)
		nb *= (-1);
	i = 1;
	while (nb / i >= 10)
		i *= 10;
	return (i);
}

static size_t			get_size(int n)
{
	size_t			i;
	unsigned int	nb;

	if (n == 0)
		return (1);
	i = 0;
	nb = n;
	if (n < 0)
	{
		i = 1;
		nb *= (-1);
	}
	while (nb != 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

static char				*itoa_arr(char *s, size_t size, size_t div, int n)
{
	size_t			i;
	unsigned int	nb;

	nb = n;
	i = 0;
	if (n < 0)
	{
		nb *= (-1);
		s[i] = '-';
		i++;
	}
	while (i < size)
	{
		s[i] = nb / div + '0';
		nb %= div;
		div /= 10;
		i++;
	}
	return (s);
}

char					*ft_itoa(int n)
{
	char		*s;
	size_t		size;
	int			div;

	size = get_size(n);
	if (!(s = ft_calloc(size + 1, sizeof(*s))))
		return (NULL);
	div = get_div(n);
	return (itoa_arr(s, size, div, n));
}
