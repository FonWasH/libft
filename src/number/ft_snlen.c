/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:48:57 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 02:34:01 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_snlen(ssize_t n, size_t base_size)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = ft_abs(n);
	if (n <= 0)
		i++;
	while (a)
	{
		i++;
		a /= base_size;
	}
	return (i);
}
