/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:05:15 by dbelinsk          #+#    #+#             */
/*   Updated: 2019/11/20 12:50:32 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		put_next_nbr(unsigned int n, int fd)
{
	if (n > 10)
		put_next_nbr(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		nb *= (-1);
		ft_putchar_fd('-', fd);
	}
	put_next_nbr(nb, fd);
}
