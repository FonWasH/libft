/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:41:19 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 00:55:28 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa_base(size_t n, char *base)
{
	char	*s;
	size_t	blen;
	size_t	nlen;

	blen = ft_strlen(base);
	nlen = ft_snlen(n, blen);
	s = (char *)malloc(sizeof(char) * (nlen + 1));
	if (!s)
		return (NULL);
	s[nlen] = '\0';
	if (n == 0)
		*s = '0';
	while (n)
	{
		s[--nlen] = base[n % blen];
		n /= blen;
	}
	return (s);
}
