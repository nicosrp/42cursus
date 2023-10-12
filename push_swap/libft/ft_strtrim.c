/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:34:40 by nsherpa           #+#    #+#             */
/*   Updated: 2023/02/17 18:09:39 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcontain(char const *set, char c)
{
	while (*set)
	{
		if (*(set++) == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			l;
	size_t			ta;
	unsigned int	tb;

	if (!s1 || !set)
		return (NULL);
	l = 0;
	while (s1[l] && ft_strcontain(set, s1[l]))
		l++;
	tb = l;
	ta = 0;
	while (s1[l])
	{
		if (ft_strcontain(set, s1[l++]))
			ta++;
		else
			ta = 0;
	}
	return (ft_substr(s1, tb, l - tb - ta));
}
