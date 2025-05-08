/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 03:14:28 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 00:58:41 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strldup(char *s, size_t n)
{
	char	*d;

	d = (char *)malloc(n + 1);
	if (!d)
		return (NULL);
	ft_strlcpy(d, s, n + 1);
	return (d);
}
