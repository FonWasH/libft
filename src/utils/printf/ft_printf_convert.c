/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 00:44:25 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 01:00:19 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_convert_chr(t_conv *conv, va_list args, int *count)
{
	if (ft_putspace(!conv->flags[DOT], conv->prec, 1, count) < 0)
		return (-1);
	if (ft_putchar((char)va_arg(args, int), 1) < 0)
		return (-1);
	*count += 1;
	if (ft_putspace(conv->flags[MINUS], conv->width, 1, count) < 0)
		return (-1);
	return (0);
}

int	ft_convert_str(t_conv *conv, va_list args, int *count)
{
	size_t	len;
	char	*str;
	char	*arg;

	arg = va_arg(args, char *);
	if (!arg)
		str = "(null)";
	else
		str = arg;
	len = ft_strlen(str);
	if (!arg && conv->prec && conv->prec < 6)
		len = 0;
	if (conv->flags[DOT] && conv->dprec < len)
		len = conv->dprec;
	if (ft_putspace(true, conv->prec, len, count) < 0)
		return (-1);
	if (ft_putlstr(str, 1, len) < 0)
		return (-1);
	*count += len;
	if (ft_putspace(conv->flags[MINUS], conv->width, len, count) < 0)
		return (-1);
	return (0);
}

int	ft_convert_ptr(t_conv *conv, va_list args, int *count)
{
	size_t	len;
	size_t	arg;
	char	*str;

	arg = (size_t)va_arg(args, void *);
	if (!arg)
		str = ft_strdup("(nil)");
	else
		str = ft_convertlubase(arg, conv, B16, PRE);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	if (!arg && conv->prec && conv->prec < 5)
		len = 0;
	if (ft_putspace(!conv->flags[DOT], conv->prec, len, count) < 0)
		return (free(str), -1);
	if (ft_putlstr(str, 1, len) < 0)
		return (free(str), -1);
	*count += len;
	if (ft_putspace(conv->flags[MINUS], conv->width, len, count) < 0)
		return (free(str), -1);
	return (free(str), 0);
}

int	ft_convert_num(t_conv *conv, va_list args, int *count, bool issigned)
{
	size_t	len;
	char	*str;

	if (issigned)
		str = ft_convertlbase(va_arg(args, int), conv, B10, "");
	else
		str = ft_convertlbase(va_arg(args, unsigned int), conv, B10, "");
	if (!str)
		return (-1);
	len = ft_strlen(str);
	if (ft_putspace(!conv->flags[DOT], conv->prec, len, count) < 0)
		return (free(str), -1);
	if (ft_putlstr(str, 1, len) < 0)
		return (free(str), -1);
	*count += len;
	if (ft_putspace(conv->flags[MINUS], conv->width, len, count) < 0)
		return (free(str), -1);
	return (free(str), 0);
}

int	ft_convert_hex(t_conv *conv, va_list args, int *count, bool isupper)
{
	size_t	len;
	char	*str;

	if (conv->flags[HASH])
		str = ft_convertlbase(va_arg(args, unsigned int), conv, B16, PRE);
	else
		str = ft_convertlbase(va_arg(args, unsigned int), conv, B16, "");
	if (!str)
		return (-1);
	if (isupper)
		ft_strtoupper(str);
	len = ft_strlen(str);
	if (ft_putspace(!conv->flags[DOT], conv->prec, len, count) < 0)
		return (free(str), -1);
	if (ft_putlstr(str, 1, len) < 0)
		return (free(str), -1);
	*count += len;
	if (ft_putspace(conv->flags[MINUS], conv->width, len, count) < 0)
		return (free(str), -1);
	return (free(str), 0);
}
