/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:24:23 by nsherpa           #+#    #+#             */
/*   Updated: 2023/03/13 17:14:07 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbrpf(int i)
{
	if (i == -2147483648)
	{
		ft_putcharpf('-');
		ft_putcharpf('2');
		i = 147483648;
	}
	if (i < 0)
	{
		ft_putcharpf('-');
		i = -i;
	}
	if (i <= 9)
	{
		ft_putcharpf(i + 48);
		return ;
	}
	else
	{
		ft_putnbrpf(i / 10);
	}
	ft_putnbrpf(i % 10);
}

void	ft_putunbrpf(unsigned int u)
{
	if (u > 9)
		ft_putunbrpf(u / 10);
	ft_putcharpf((u % 10) + '0');
}

int	ft_putnbrpf_hex(unsigned int u, char c)
{
	char	*base;
	int		len;

	len = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (u >= 16)
	{
		len = ft_putnbrpf_hex(u / 16, c);
	}
	ft_putcharpf(base[u % 16]);
	len ++;
	return (len);
}

int	ft_ptrpf(uintptr_t u)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789abcdef";
	if (u >= 16)
	{
		len = ft_ptrpf(u / 16);
	}
	ft_putcharpf(base[u % 16]);
	len ++;
	return (len);
}
