/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:24:42 by nsherpa           #+#    #+#             */
/*   Updated: 2023/02/17 17:57:40 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	mem;
	char	*ptr;

	mem = count * size;
	if (size != 0 && mem / size != count)
		return (NULL);
	ptr = malloc(mem);
	if (ptr == 0)
		return (NULL);
	ptr = ft_memset(ptr, 0, mem);
	return (ptr);
}
