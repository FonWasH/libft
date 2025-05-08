/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:41:02 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 00:58:14 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcount(char *s, int c)
{
	size_t	i;
	bool	sep;

	sep = true;
	i = 0;
	while (*s)
	{
		if (*s == (char)c)
			sep = true;
		if (*s != (char)c && sep)
		{
			sep = false;
			i++;
		}
		s++;
	}
	return (i);
}
