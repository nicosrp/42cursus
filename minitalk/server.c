/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <nsherpa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:35:37 by nsherpa           #+#    #+#             */
/*   Updated: 2023/10/03 15:13:09 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

void	ft_receiver(int sign)
{
	static int	x;
	static int	y;

	if (sign == SIGUSR1)
	{
		y *= 2;
		y += 1;
		x++;
	}
	else
	{
		y *= 2;
		x++;
	}
	if (x == 8)
	{
		ft_printf("%c", y);
		x = 0;
		y = 0;
	}
}

int	main(void)
{
	struct sigaction	signal;
	pid_t				pid;

	signal.sa_handler = &ft_receiver;
	signal.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	pid = getpid();
	ft_printf(" %d\n", pid);
	while (1)
		pause();
}
