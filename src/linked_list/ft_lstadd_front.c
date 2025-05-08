/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 05:28:09 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 00:56:12 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!(*lst))
	{
		new->prev = NULL;
		new->next = NULL;
		*lst = new;
		return ;
	}
	tmp = ft_lstfirst(*lst);
	tmp->prev = new;
	new->prev = NULL;
	new->next = tmp;
	*lst = new;
}
