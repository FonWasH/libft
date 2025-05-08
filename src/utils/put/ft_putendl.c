/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:51:38 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 00:59:45 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putendl(char *s, int fd)
{
	ssize_t	i;

	i = ft_putstr(s, fd);
	if (i < 0)
		return (-1);
	i += ft_putchar(fd, '\n');
	return (i);
}
