/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <nsherpa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:58:26 by nsherpa           #+#    #+#             */
/*   Updated: 2023/08/05 19:24:50 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(t_gamedetails *game)
{
	int	i;

	i = 0;
	if (game->winpointer)
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	free(game->mlxpointer);
	while (i < game->map_height - 1)
		free(game->map[i++]);
	free(game->map);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_gamedetails	game;

	if (argc != 2)
	{
		ft_printf("Error\n");
		ft_printf("ArgCError\n");
		return (0);
	}
	ft_memset(&game, 0, sizeof(t_gamedetails));
	get_mapdata(&game, argv);
	setup_check(&game);
	game.mlxpointer = mlx_init();
	game.winpointer = mlx_new_window(game.mlxpointer, (game.map_width * 40),
			(game.map_height * 40), "solong");
	adding_allimages(&game);
	mlx_key_hook(game.winpointer, commands, &game);
	mlx_hook(game.winpointer, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlxpointer);
}
