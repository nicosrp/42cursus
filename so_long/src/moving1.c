/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <nsherpa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:57:46 by nsherpa           #+#    #+#             */
/*   Updated: 2023/08/04 19:13:47 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_left(t_gamedetails *game)
{
	int	i;
	int	j;
	int	k;

	i = game->player_x - 1;
	j = game->player_y;
	if (game->map[j][i] == '1')
		return (0);
	k = restricted_moving(game, i, j);
	if (!k)
		return (0);
	game->map[j][i + 1] = '0';
	ft_printf("Step Counter: %i\n", game->step_counter);
	ft_printf("Remaining Items: %i\n", game->collectables);
	return (1);
}

static int	move_right(t_gamedetails *game)
{
	int	i;
	int	j;
	int	k;

	i = game->player_x + 1;
	j = game->player_y;
	if (game->map[j][i] == '1')
		return (0);
	k = restricted_moving(game, i, j);
	if (!k)
		return (0);
	game->map[j][i - 1] = '0';
	ft_printf("Step Counter: %i\n", game->step_counter);
	ft_printf("Remaining Items: %i\n", game->collectables);
	return (1);
}

static int	moving_leftright(t_gamedetails *game, int movement)
{
	if (movement == 0)
		return (move_left(game));
	else if (movement == 2)
		return (move_right(game));
	else
		return (0);
}

int	controls_working(int command, t_gamedetails *game)
{
	int	works;

	if (command == 53)
		end_game(game);
	if (command == 13)
		works = moving_updown(game, command);
	if (command == 1)
		works = moving_updown(game, command);
	if (command == 0)
		works = moving_leftright(game, command);
	if (command == 2)
		works = moving_leftright(game, command);
	if (works)
		adding_in_graphics(game);
	return (1);
}
