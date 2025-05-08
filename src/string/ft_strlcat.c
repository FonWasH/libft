/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:52:20 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 00:58:33 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *d, char *s, size_t n)
{
	size_t	dlen;
	size_t	i;

	dlen = ft_strlen(d);
	if (n <= dlen)
		return (n + ft_strlen(s));
	i = 0;
	while (s[i] && i + dlen + 1 < n)
	{
		d[dlen + i] = s[i];
		i++;
	}
	d[dlen + i] = '\0';
	return (dlen + ft_strlen(s));
}
