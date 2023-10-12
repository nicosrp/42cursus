/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:55:51 by nsherpa           #+#    #+#             */
/*   Updated: 2023/02/17 18:05:11 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fill(char **a, const char *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i + j] == c || s[i + j] == 0)
		{
			a[k++] = ft_substr(s, i, j);
			i += j;
			j = 0;
		}
		else
			j++;
	}
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**a;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (s[i++])
	{
		if (s[i - 1] != c && (s[i] == c || s[i] == 0))
			k++;
	}
	a = ft_calloc(k + 1, sizeof (char *));
	if (!a)
		return (NULL);
	a[k] = 0;
	ft_fill(a, s, c);
	return (a);
}
