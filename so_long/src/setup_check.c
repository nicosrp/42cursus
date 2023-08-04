/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <nsherpa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:58:17 by nsherpa           #+#    #+#             */
/*   Updated: 2023/08/04 18:45:57 by nsherpa          ###   ########.fr       */
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
		ft_printf("\nNo usable Character:%c\n", game->map[h][w]);
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
		ft_printf("Character Error (C/P/E)\n");
		end_game(game);
	}
}

static int	is_upperlowerpresent(t_gamedetails *game)
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

static int	is_leftrightpresent(t_gamedetails *game)
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
	if (!is_upperlowerpresent(game) || !is_leftrightpresent(game))
	{
		ft_printf("\nMissingWallsError\n");
		end_game(game);
	}
}
