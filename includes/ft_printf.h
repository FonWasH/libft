/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 00:31:59 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 03:03:47 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define PRE "0x"

typedef enum e_specs
{
	CHAR,
	STRING,
	POINTER,
	DECIMAL,
	INT,
	UINT,
	HEXA,
	HEXA_UPPER,
	PERCENT
}	t_specs;

typedef enum e_flags
{
	MINUS,
	ZERO,
	DOT,
	HASH,
	SPACE,
	PLUS
}	t_flags;

typedef struct s_conv
{
	bool	flags[6];
	size_t	width;
	size_t	dprec;
	size_t	prec;
	int		spec;
}			t_conv;

typedef struct s_nb
{
	char	*str;
	ssize_t	nbr;
	size_t	abs;
	size_t	nlen;
	size_t	blen;
	size_t	sgn;
	size_t	pre;
	size_t	zero;
}			t_nb;

void	ft_init_conv(t_conv *conv);
int		ft_isflag(char c);
int		ft_isspec(char c);
int		ft_putspace(bool isflag, int size, int len, int *count);
char	*ft_convertlbase(ssize_t n, t_conv *conv, char *base, char *pre);
char	*ft_convertlubase(size_t n, t_conv *conv, char *base, char *pre);
int		ft_convert_chr(t_conv *conv, va_list args, int *count);
int		ft_convert_str(t_conv *conv, va_list args, int *count);
int		ft_convert_ptr(t_conv *conv, va_list args, int *count);
int		ft_convert_num(t_conv *conv, va_list args, int *count, bool issigned);
int		ft_convert_hex(t_conv *conv, va_list args, int *count, bool isupper);

#endif
