/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 04:47:43 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 00:57:41 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *p, size_t old, size_t new)
{
	void	*d;

	if (new == 0)
		return (free(p), NULL);
	if (!p)
		return (malloc(new));
	if (old >= new)
		return (p);
	d = malloc(new);
	if (!d)
		return (free(p), NULL);
	ft_memcpy(d, p, old);
	return (free(p), d);
}
