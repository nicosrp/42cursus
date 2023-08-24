/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <nsherpa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:35:00 by nsherpa           #+#    #+#             */
/*   Updated: 2023/08/24 20:09:06 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

void	ft_minitalk(char *str, gid_t pid)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((1 << bit) & *str)
		{
			kill(pid, SIGUSR1);
			usleep(300);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep(300);
		}
		bit--;
	}
}

int	main(int ac, char *av[])
{
	pid_t	pid;
	int		i;

	i = -1;
	if (ac != 3)
	{
		ft_printf("Failed to process input, must be: [PID] [MESSAGE]");
		return (0);
	}
	else
	{
		pid = ft_atoi(av[1]);
		while (av[2][++i])
			ft_minitalk(&av[2][i], pid);
		ft_printf("Sent Message: %s", av[2]);
	}
}
