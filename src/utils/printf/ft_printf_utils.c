/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:39:27 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 01:00:31 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_init_conv(t_conv *conv)
{
	size_t	i;

	i = 0;
	while (i < 6)
		conv->flags[i++] = false;
	conv->width = 0;
	conv->dprec = 0;
	conv->prec = 0;
	conv->spec = -1;
}

int	ft_isflag(char c)
{
	const char	flags[] = "-0.# +";
	int			i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_isspec(char c)
{
	const char	specs[] = "cspdiuxX%";
	int			i;

	i = 0;
	while (specs[i])
	{
		if (specs[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_putspace(bool isflag, int size, int len, int *count)
{
	if (isflag && size > len)
	{
		if (ft_putnchar(' ', 1, size - len) < 0)
			return (-1);
		*count += size - len;
	}
	return (0);
}
