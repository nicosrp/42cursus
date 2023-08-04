/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 12:12:07 by nsherpa           #+#    #+#             */
/*   Updated: 2023/03/13 17:30:29 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlenpf(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putcharpf(char c)
{
	write(1, &c, 1);
}

void	ft_putstrpf(char *str)
{
	if (!str)
	{
		write(1, "(null)", 6);
		return ;
	}
	write(1, str, ft_strlenpf(str));
}
