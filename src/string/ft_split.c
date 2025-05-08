/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:51:54 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 00:57:56 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char *s, char c)
{
	char	**tab;
	size_t	count;
	size_t	len;
	size_t	i;

	count = ft_strcount(s, c);
	tab = (char **)malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*s == c)
			s++;
		len = ft_strllen(s, c);
		tab[i] = ft_substr(s, 0, len);
		if (!tab[i])
			return (ft_mfree((void **)tab, i), NULL);
		s += len;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
