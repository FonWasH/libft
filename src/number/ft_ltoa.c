/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:50:57 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 00:55:18 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa(ssize_t n)
{
	char	*s;
	size_t	a;
	size_t	nlen;

	nlen = ft_snlen(n, 10);
	s = (char *)malloc(sizeof(char) * (nlen + 1));
	if (!s)
		return (NULL);
	s[nlen] = '\0';
	if (n == 0)
		*s = '0';
	if (n < 0)
		*s = '-';
	a = ft_abs(n);
	while (a)
	{
		s[--nlen] = (a % 10) + '0';
		a /= 10;
	}
	return (s);
}
