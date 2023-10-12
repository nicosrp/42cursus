/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:21:02 by nsherpa           #+#    #+#             */
/*   Updated: 2023/02/17 18:03:46 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*s_dst;
	char	*s_src;

	if (dst == 0 && src == 0)
		return (dst);
	s_dst = (char *) dst;
	s_src = (char *) src;
	i = 0;
	while (i < n)
	{
		s_dst[i] = s_src[i];
		i ++;
	}
	return (dst);
}
