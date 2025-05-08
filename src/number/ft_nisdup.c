/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nisdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 21:35:01 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 00:55:22 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_nisdup(int *tab, size_t size, int n)
{
	while (size--)
	{
		if (tab[size] == n)
			return (true);
	}
	return (false);
}
