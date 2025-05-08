/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:34:00 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 01:00:42 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static size_t	ft_parse_conv(const char *format, t_conv *conv)
{
	size_t	i;
	int		flag;

	i = 0;
	while (format[++i] && ft_isspec(format[i]) < 0)
	{
		flag = ft_isflag(format[i]);
		if (flag >= 0)
		{
			conv->flags[flag] = true;
			if (flag == SPACE && ft_isdigit(format[i + 1]))
				conv->prec = ft_atol((char *)format + i + 1);
			if (flag == DOT && ft_isdigit(format[i + 1]))
				conv->dprec = ft_atol((char *)format + i + 1);
			if ((flag == MINUS || flag == ZERO) && ft_isdigit(format[i + 1]))
				conv->width = ft_atol((char *)format + i + 1);
		}
		else if (ft_isdigit(format[i]))
			conv->prec = ft_atol((char *)format + i);
		while (ft_isdigit(format[i + 1]))
			i++;
	}
	conv->spec = ft_isspec(format[i++]);
	return (i);
}

static int	ft_convert_arg(t_conv *conv, va_list args, int *count)
{
	if (conv->spec == CHAR)
		return (ft_convert_chr(conv, args, count));
	else if (conv->spec == STRING)
		return (ft_convert_str(conv, args, count));
	else if (conv->spec == POINTER)
		return (ft_convert_ptr(conv, args, count));
	else if (conv->spec == DECIMAL || conv->spec == INT)
		return (ft_convert_num(conv, args, count, true));
	else if (conv->spec == UINT)
		return (ft_convert_num(conv, args, count, false));
	else if (conv->spec == HEXA)
		return (ft_convert_hex(conv, args, count, false));
	else if (conv->spec == HEXA_UPPER)
		return (ft_convert_hex(conv, args, count, true));
	else if (conv->spec == PERCENT)
	{
		if (ft_putchar('%', 1) < 0)
			return (-1);
		*count += 1;
	}
	return (0);
}

static int	ft_print_arg(const char *format, va_list args, int *count)
{
	size_t	len;
	t_conv	conv;

	ft_init_conv(&conv);
	len = ft_parse_conv(format, &conv);
	if (conv.spec < 0)
		return (-1);
	if (ft_convert_arg(&conv, args, count) < 0)
		return (-1);
	return (len);
}

static int	ft_parse_format(const char *format, va_list args, int count)
{
	int	len;

	while (*format)
	{
		if (*format == '%')
		{
			len = ft_print_arg(format, args, &count);
			if (len < 0)
				return (-1);
			format += len;
		}
		else
		{
			if (ft_putchar(*format, 1) < 0)
				return (-1);
			count++;
			format++;
		}
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = ft_parse_format(format, args, 0);
	return (va_end(args), count);
}
