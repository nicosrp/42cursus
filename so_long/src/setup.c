/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <nsherpa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:57:59 by nsherpa           #+#    #+#             */
/*   Updated: 2023/08/05 17:25:47 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setup_collectable(t_gamedetails *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->collectable, width * 40, height * 40);
	game->collectables++;
}

void	setup_player(t_gamedetails *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->player, width * 40, height * 40);
	game->player_y = height;
	game->player_x = width;
}

static void	match_images(t_gamedetails *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"image_res/floor.xpm", &i, &j);
	game->barrier = mlx_xpm_file_to_image(game->mlxpointer,
			"image_res/barrier.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"image_res/player.xpm", &i, &j);
	game->door = mlx_xpm_file_to_image(game->mlxpointer,
			"image_res/door.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"image_res/collectable.xpm", &i, &j);
}

static void	place_images(
		t_gamedetails *game,
		char symbol,
		int height,
		int width)
{
	if (symbol == '1')
		mlx_put_image_to_window(
			game->mlxpointer,
			game->winpointer,
			game->barrier,
			width * 40,
			height * 40);
	else if (symbol == 'C')
		setup_collectable(game, height, width);
	else if (symbol == 'P')
		setup_player(game, height, width);
	else if (symbol == 'E')
		mlx_put_image_to_window(
			game->mlxpointer,
			game->winpointer,
			game->door,
			width * 40,
			height * 40);
	else if (symbol == '0')
		mlx_put_image_to_window(
			game->mlxpointer,
			game->winpointer,
			game->floor,
			width * 40,
			height * 40);
}

void	adding_allimages(t_gamedetails *game)
{
	int	h;
	int	w;

	match_images(game);
	game->collectables = 0;
	h = 0;
	while (h < game->map_height)
	{
		w = 0;
		while (game->map[h][w])
		{
			place_images(game, game->map[h][w], h, w);
			w++;
		}
		h++;
	}
}
