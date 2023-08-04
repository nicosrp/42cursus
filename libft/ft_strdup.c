/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:57:13 by nsherpa           #+#    #+#             */
/*   Updated: 2023/02/17 18:07:20 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*s2;

	len = 0;
	i = 0;
	while (s1[len++])
		;
	s2 = ft_calloc(len, sizeof(char));
	if (!s2)
		return (NULL);
	while (i < len)
	{
		s2[i++] = *(s1++);
	}
	return (s2);
}
