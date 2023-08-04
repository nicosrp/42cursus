/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:06:35 by nsherpa           #+#    #+#             */
/*   Updated: 2023/02/17 18:04:01 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*s_dst;
	char	*s_src;

	if (src == dst)
		return (dst);
	else if (src > dst)
		return (ft_memcpy(dst, src, len));
	i = 0;
	s_dst = (char *)dst;
	s_src = (char *)src;
	while (len-- > 0)
		s_dst[len] = s_src[len];
	return (dst);
}
