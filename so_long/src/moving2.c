/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <nsherpa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:11:51 by nsherpa           #+#    #+#             */
/*   Updated: 2023/08/04 19:13:44 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	restricted_moving(t_gamedetails *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		ft_printf("\nsweet sweet victory!!!\n");
		end_game(game);
	}
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->player_x = i;
		game->player_y = j;
		game->step_counter++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->player_x = i;
		game->player_y = j;
		game->collectables--;
		game->step_counter++;
	}
	return (1);
}

static int	move_up(t_gamedetails *game)
{
	int	i;
	int	j;
	int	k;

	i = game->player_x;
	j = game->player_y - 1;
	if (game->map[j][i] == '1')
		return (0);
	k = restricted_moving(game, i, j);
	if (!k)
		return (0);
	game->map[j + 1][i] = '0';
	ft_printf("Step Coußnter: %i\n", game->step_counter);
	ft_printf("Remaining Items: %i\n", game->collectables);
	return (1);
}

static int	move_down(t_gamedetails *game)
{
	int	i;
	int	j;
	int	k;

	i = game->player_x;
	j = game->player_y + 1;
	if (game->map[j][i] == '1')
		return (0);
	k = restricted_moving(game, i, j);
	if (!k)
		return (0);
	game->map[j - 1][i] = '0';
	ft_printf("Step Counter: %i\n", game->step_counter);
	ft_printf("Remaining Items: %i\n", game->collectables);
	return (1);
}

int	moving_updown(t_gamedetails *game, int movement)
{
	if (movement == 13)
		return (move_up(game));
	else if (movement == 1)
		return (move_down(game));
	else
		return (0);
}
