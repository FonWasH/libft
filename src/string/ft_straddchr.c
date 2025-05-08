/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:14:18 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 00:58:02 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_straddchr(char *s, char c)
{
	char	*new;
	size_t	len;

	len = ft_strlen(s);
	new = (char *)malloc(sizeof(char) * (len + 3));
	if (!new)
		return (NULL);
	new[0] = c;
	ft_strlcpy(new + 1, s, len + 1);
	new[len + 1] = c;
	new[len + 2] = '\0';
	return (new);
}
