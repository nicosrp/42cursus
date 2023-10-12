/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:03:47 by nsherpa           #+#    #+#             */
/*   Updated: 2023/02/17 18:09:16 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	if (needle[0] == 0)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	i = 0;
	while (haystack[i] != 0 && i < len)
	{
		k = 0;
		while (needle[k] != 0)
		{
			if (haystack[i + k] == needle[k] && i + k < len)
			{
				if (needle[k + 1] == 0)
					return ((char *) &haystack[i]);
				k++;
			}
			else
				break ;
		}
		i++;
	}
	return (NULL);
}
