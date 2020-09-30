/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelinsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:51:35 by dbelinsk          #+#    #+#             */
/*   Updated: 2019/11/18 17:33:25 by dbelinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void *content)
{
	t_list		*node;

	if (!(node = (t_list*)malloc(sizeof(*node))))
		return (NULL);
	if (!content)
		node->content = NULL;
	else
		node->content = content;
	node->next = NULL;
	return (node);
}
