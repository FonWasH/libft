/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:49:50 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 00:55:09 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_atol(char *s)
{
	size_t	n;
	int		sgn;

	while (ft_isspace(*s))
		s++;
	sgn = 1 - (2 * (*s == '-'));
	s += (*s == '-' || *s == '+');
	n = 0;
	while (ft_isdigit(*s))
	{
		n = (n * 10) + (*s - '0');
		if (n > (size_t)LONG_MAX + (sgn < 0))
			return (0 - (1 * (sgn > 0)));
		s++;
	}
	return ((ssize_t)n * sgn);
}
