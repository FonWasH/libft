/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convertbase.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:31:49 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 01:00:25 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	ft_add_sign_zero_snum(t_nb *nb, t_conv *conv, char *pre)
{
	ft_memset(nb->str, 0, nb->nlen + nb->sgn + nb->pre + nb->zero + 1);
	if (nb->nbr == 0)
		nb->str[0 + nb->sgn + nb->pre + nb->zero] = '0';
	if (nb->nbr < 0)
		nb->str[0] = '-';
	if (nb->nbr >= 0 && conv->flags[PLUS])
		nb->str[0] = '+';
	else if (nb->nbr >= 0 && conv->flags[SPACE])
		nb->str[0] = ' ';
	ft_memcpy(nb->str + nb->sgn, pre, nb->pre);
	ft_memset(nb->str + nb->sgn + nb->pre, '0', nb->zero);
}

char	*ft_convertlbase(ssize_t n, t_conv *conv, char *base, char *pre)
{
	t_nb	nb;

	nb.nbr = n;
	nb.abs = ft_abs(n);
	nb.blen = ft_strlen(base);
	nb.nlen = ft_snlen(nb.abs, nb.blen);
	nb.sgn = (((conv->flags[PLUS] || conv->flags[SPACE]) && n >= 0) || (n < 0));
	nb.pre = ft_strlen(pre) * (n > 0);
	nb.zero = 0;
	if (conv->flags[DOT] && conv->dprec > nb.nlen)
		nb.zero = conv->dprec - nb.nlen;
	else if (conv->flags[ZERO] && conv->width > (nb.nlen + nb.sgn + nb.pre))
		nb.zero = conv->width - (nb.nlen + nb.sgn + nb.pre);
	nb.str = (char *)malloc(nb.nlen + nb.sgn + nb.pre + nb.zero + 1);
	if (!nb.str)
		return (NULL);
	ft_add_sign_zero_snum(&nb, conv, pre);
	while (nb.abs)
	{
		nb.str[--nb.nlen + nb.sgn + nb.pre + nb.zero] = base[nb.abs % nb.blen];
		nb.abs /= nb.blen;
	}
	return (nb.str);
}

static void	ft_add_sign_zero_unum(t_nb *nb, t_conv *conv, char *pre)
{
	ft_memset(nb->str, 0, nb->nlen + nb->sgn + nb->pre + nb->zero + 1);
	if (nb->abs == 0)
		nb->str[0 + nb->sgn + nb->pre + nb->zero] = '0';
	if (conv->flags[PLUS])
		nb->str[0] = '+';
	else if (conv->flags[SPACE])
		nb->str[0] = ' ';
	ft_memcpy(nb->str + nb->sgn, pre, nb->pre);
	ft_memset(nb->str + nb->sgn + nb->pre, '0', nb->zero);
}

char	*ft_convertlubase(size_t n, t_conv *conv, char *base, char *pre)
{
	t_nb	nb;

	nb.abs = n;
	nb.blen = ft_strlen(base);
	nb.nlen = ft_unlen(n, nb.blen);
	nb.sgn = (conv->flags[PLUS] || conv->flags[SPACE]);
	nb.pre = ft_strlen(pre) * (n > 0);
	nb.zero = 0;
	if (conv->flags[DOT] && conv->dprec > nb.nlen)
		nb.zero = conv->dprec - nb.blen;
	else if (conv->flags[ZERO] && conv->width > (nb.nlen + nb.sgn + nb.pre))
		nb.zero = conv->width - (nb.nlen + nb.sgn + nb.pre);
	nb.str = (char *)malloc(nb.nlen + nb.sgn + nb.pre + nb.zero + 1);
	if (!nb.str)
		return (NULL);
	ft_add_sign_zero_unum(&nb, conv, pre);
	while (nb.abs)
	{
		nb.str[--nb.nlen + nb.sgn + nb.pre + nb.zero] = base[nb.abs % nb.blen];
		nb.abs /= nb.blen;
	}
	return (nb.str);
}
