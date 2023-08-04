/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:35:38 by nsherpa           #+#    #+#             */
/*   Updated: 2023/03/13 17:55:20 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	list;

	count = 0;
	i = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putcharpf(str[i]);
			count ++;
		}
		else
		{
			i ++;
			count += ft_checkpf(str[i], &list);
		}
		i ++;
	}
	va_end(list);
	return (count);
}
