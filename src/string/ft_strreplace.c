/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:50:37 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 00:59:11 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *s1, char *s2, size_t start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	j;

	new = malloc((ft_strlen(s1) + ft_strlen(s2)) - len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < start)
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		new[i++] = s2[j++];
	j = start + len;
	while (s1[j])
		new[i++] = s1[j++];
	new[i] = '\0';
	return (new);
}
