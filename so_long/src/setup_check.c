/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:33:01 by prossi            #+#    #+#             */
/*   Updated: 2022/12/12 20:46:47 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_countsetup(t_gamedetails *game, int h, int w)
{
	if (game->map[h][w] != 'P' &&
		game->map[h][w] != 'E' &&
		game->map[h][w] != 'C' &&
		game->map[h][w] != '1' &&
		game->map[h][w] != '0' &&
		game->map[h][w] != '\n')
	{
		printf("\nNo usable Character:%c\n", game->map[h][w]);
		end_game(game);
	}
	if (game->map[h][w] == 'C')
			game->columncount++;
	if (game->map[h][w] == 'P')
			game->playercount++;
	if (game->map[h][w] == 'E')
			game->exitcount++;
}

void	check_mapchars(t_gamedetails *game)
{
	int	h;
	int	w;

	h = 0;
	while (h < game->heightmap - 1)
	{
		w = 0;
		while (w <= game->widthmap)
		{
			check_countsetup(game, h, w);
			w++;
		}
		h++;
	}
	if (!(game->playercount == 1 && game->columncount > 1
			&& game->exitcount == 1))
	{
		printf("Character Error (C/P/E)\n");
		end_game(game);
	}
}

static int	is_upperLowerWallPresent(t_gamedetails *game)
{
	int	i;
	int	j;

	i = game->widthmap;
	j = 0;
	while (j < i)
	{
		if (game->map[0][i] == '1' && game->map[game->heightmap - 1][j] == '1')
			return (0);
		j++;
	}
	return (1);
}

static int	is_leftRigthWallPresent(t_gamedetails *game)
{
	int	i;
	int	j;

	i = game->widthmap;
	j = 0;
	while (j < game->heightmap)
	{
		if (!(game->map[j][0] == '1' && game->map[j][i - 1] == '1'))
			return (0);
		j++;
	}
	return (1);
}

void	setup_check(t_gamedetails *game)
{
	check_mapchars(game);
	if (!is_upperLowerWallPresent(game) || !is_leftRigthWallPresent(game))
	{
		printf("\nMissingWallsError\n");
		end_game(game);
	}
}
