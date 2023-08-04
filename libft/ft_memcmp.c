/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:18:13 by nsherpa           #+#    #+#             */
/*   Updated: 2023/02/17 18:03:23 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s_s1;
	unsigned char	*s_s2;
	size_t			i;

	s_s1 = (unsigned char *)s1;
	s_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s_s1[i] != s_s2[i])
			return ((int)s_s1[i] - (int)s_s2[i]);
		i++;
	}
	return (0);
}
