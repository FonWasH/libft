/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:52:14 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 00:58:29 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*d;
	size_t	i;

	d = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!d)
		return (NULL);
	i = 0;
	while (*s1)
		d[i++] = *s1++;
	while (*s2)
		d[i++] = *s2++;
	d[i] = '\0';
	return (d);
}

char	*ft_strjoin_free(char *s1, char *s2, int f)
{
	char	*d;

	d = ft_strjoin(s1, s2);
	if (f == 1 || f == 3)
		free(s1);
	if (f == 2 || f == 3)
		free(s2);
	return (d);
}
