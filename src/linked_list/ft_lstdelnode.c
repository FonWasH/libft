/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:41:21 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 00:56:19 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdelnode(t_list **lst, t_list *node)
{
	t_list	*tmp;

	if (node->prev)
	{
		node->prev->next = node->next;
		tmp = node->prev;
	}
	else
	{
		*lst = node->next;
		tmp = node->next;
	}
	if (node->next)
		node->next->prev = node->prev;
	ft_lstdelone(node, free);
	return (tmp);
}
