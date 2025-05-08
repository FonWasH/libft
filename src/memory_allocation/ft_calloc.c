/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:50:25 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 00:57:32 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t e, size_t n)
{
	void	*p;

	if (e && n && SIZE_MAX / e < n)
		return (NULL);
	p = malloc(e * n);
	if (!p)
		return (NULL);
	return (ft_memset(p, 0, e * n));
}
