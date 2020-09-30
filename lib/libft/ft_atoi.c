/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:57:18 by dbelinsk          #+#    #+#             */
/*   Updated: 2019/11/20 13:16:06 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		is_neg(char c)
{
	if ((c < '0' || c > '9') && c != '-' && c != '+')
		return (0);
	else if (c == '-')
		return (-1);
	else
		return (1);
}

int				ft_atoi(const char *str)
{
	int						neg;
	unsigned long			res;

	res = -1;
	while (*str == '\t' || *str == '\n' || *str == '\v' ||
			*str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if ((neg = is_neg(*str)) == -1 || *str == '+')
		str++;
	if (*str < '0' || *str > '9')
		return (0);
	while (*str && *str >= '0' && *str <= '9')
	{
		if (res == -1UL)
			res = *str - '0';
		else
			res = res * 10 + *str - '0';
		str++;
		if (res >= 9223372036854775807UL && neg == 1)
			return (-1);
		if (res > 9223372036854775807UL && neg == -1)
			return (0);
	}
	return ((int)(res * neg));
}
