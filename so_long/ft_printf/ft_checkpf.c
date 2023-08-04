/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkpf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:15:25 by nsherpa           #+#    #+#             */
/*   Updated: 2023/03/13 17:56:14 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkpf(char c, va_list *list)
{
	char			*s;

	if (c == '%')
	{
		ft_putcharpf('%');
		return (1);
	}
	else if (c == 'c')
	{
		ft_putcharpf(va_arg(*list, int));
		return (1);
	}
	else if (c == 's')
	{
		s = va_arg(*list, char *);
		ft_putstrpf(s);
		if (!s)
			return (6);
		return (ft_strlenpf(s));
	}
	return (ft_checkpf2(c, list));
}

int	ft_checkpf2(char c, va_list *list)
{
	int	i;

	if (c == 'd' || c == 'i')
	{
		i = va_arg(*list, int);
		ft_putnbrpf(i);
		if (i < 0)
			return (ft_lenint(-i) + 1);
		return (ft_lenint(i));
	}
	return (ft_checkpf3(c, list));
}

int	ft_checkpf3(char c, va_list *list)
{
	unsigned int	u;

	if (c == 'u')
	{
		u = va_arg(*list, unsigned int);
		ft_putunbrpf(u);
		return (ft_lenuint(u));
	}
	else if (c == 'x' || c == 'X')
		return (ft_putnbrpf_hex(va_arg(*list, unsigned int), c));
	else if (c == 'p')
	{
		ft_putcharpf('0');
		ft_putcharpf('x');
		return (2 + ft_ptrpf(va_arg(*list, uintptr_t)));
	}
	return (0);
}
