/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:52:49 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 00:59:00 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *s1, char *s2, size_t n)
{
	size_t	i;

	if (!*s2)
		return (s1);
	if (!n)
		return (NULL);
	while (*s1 && n--)
	{
		i = 0;
		while (s2[i] && s1[i] == s2[i] && i <= n)
			i++;
		if (!s2[i])
			return (s1);
		s1++;
	}
	return (NULL);
}
