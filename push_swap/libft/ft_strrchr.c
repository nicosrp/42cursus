/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:44:18 by nsherpa           #+#    #+#             */
/*   Updated: 2023/02/17 18:09:30 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*out;

	out = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			out = (char *)s;
		s ++;
	}
	if (c == 0)
		return ((char *)s);
	return (out);
}
