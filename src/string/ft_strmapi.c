/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:52:36 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 00:58:53 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	char	*d;
	size_t	i;

	d = ft_strdup(s);
	if (!d)
		return (NULL);
	i = 0;
	while (d[i])
	{
		d[i] = (*f)(i, d[i]);
		i++;
	}
	return (d);
}
