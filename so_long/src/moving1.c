/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <nsherpa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:57:46 by nsherpa           #+#    #+#             */
/*   Updated: 2023/08/05 17:31:08 by nsherpa          ###   ########.fr       */
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

int	commands(int c, t_gamedetails *game)
{
	int	com;

	if (c == 53)
		end_game(game);
	if (c == 13)
		com = moving_updown(game, c);
	if (c == 1)
		com = moving_updown(game, c);
	if (c == 0)
		com = moving_leftright(game, c);
	if (c == 2)
		com = moving_leftright(game, c);
	if (com)
		adding_allimages(game);
	return (1);
}
