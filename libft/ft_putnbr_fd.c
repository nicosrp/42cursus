/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:10:22 by nsherpa           #+#    #+#             */
/*   Updated: 2023/02/17 18:04:54 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		d;
	int		mod;
	char	c;

	d = n / 10;
	mod = n % 10;
	if (n < 0)
	{
		write(fd, "-", 1);
		d = -d;
		mod = -mod;
	}
	if (d > 0)
	{
		ft_putnbr_fd(d, fd);
	}
	c = '0' + mod;
	write(fd, &c, 1);
}
