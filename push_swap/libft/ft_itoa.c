/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:04:16 by nsherpa           #+#    #+#             */
/*   Updated: 2023/02/17 18:00:50 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_recursive(int nbr, int *i)
{
	int		quotient;
	int		mod;
	char	*a;

	quotient = nbr / 10;
	mod = nbr % 10;
	(*i)++;
	if (quotient == 0)
	{
		a = ft_calloc(*i, sizeof(char));
		*i = 0;
		if (mod < 0)
			(*i)++;
	}
	else
		a = ft_recursive(quotient, i);
	if (!a)
		return (NULL);
	if (mod < 0)
		mod = -mod;
	a[*i] = mod + '0';
	(*i)++;
	return (a);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*a;

	i = 1;
	if (n < 0)
		i++;
	a = ft_recursive(n, &i);
	if (!a)
		return (NULL);
	a[i] = 0;
	if (n < 0)
		a[0] = '-';
	return (a);
}
