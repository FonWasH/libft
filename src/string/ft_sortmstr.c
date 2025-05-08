/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortmstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:40:30 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 00:57:52 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sortmstr(char **ms)
{
	char	*tmp;
	size_t	i;

	i = 0;
	while (ms[i + 1])
	{
		if (ft_strcmp(ms[i], ms[i + 1]) > 0)
		{
			tmp = ms[i];
			ms[i] = ms[i + 1];
			ms[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}
