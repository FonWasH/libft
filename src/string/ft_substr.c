/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:53:08 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 00:59:28 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, size_t start, size_t n)
{
	char	*d;
	size_t	slen;
	size_t	dlen;

	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if ((start + n) > slen)
		dlen = (slen - start) + 1;
	else
		dlen = n + 1;
	d = (char *)malloc(sizeof(char) * dlen);
	if (!d)
		return (NULL);
	ft_strlcpy(d, s + start, dlen);
	return (d);
}
