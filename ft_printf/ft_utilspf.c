/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilspf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:33:40 by nsherpa           #+#    #+#             */
/*   Updated: 2023/03/13 17:38:58 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lenuint(unsigned int n)
{
	if (n < 10)
		return (1);
	return (1 + ft_lenuint(n / 10));
}

int	ft_lenint(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}
