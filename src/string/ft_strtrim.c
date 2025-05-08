/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:53:02 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 00:59:24 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s1, char *s2)
{
	size_t	start;
	size_t	end;

	start = 0;
	while (s1[start] && ft_strchr(s2, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > 0 && ft_strchr(s2, s1[end]))
		end--;
	return (ft_substr(s1, start, (end - start + 1)));
}
