/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:08:35 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 00:55:04 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_atol_base(char *s, char *base)
{
	size_t	n;
	size_t	blen;
	char	*bpos;
	int		sgn;

	while (ft_isspace(*s))
		s++;
	sgn = 1 - (2 * (*s == '-'));
	s += (*s == '-' || *s == '+');
	n = 0;
	blen = ft_strlen(base);
	bpos = ft_strchr(base, *s);
	while (bpos && *s)
	{
		n = (n * blen) + (base - bpos);
		if (n > (size_t)LONG_MAX + (sgn < 0))
			return (0 - (1 * (sgn > 0)));
		bpos = ft_strchr(base, *++s);
	}
	return ((ssize_t)n * sgn);
}
