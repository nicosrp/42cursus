#include "so_long.h"

void	initialize(char **argv, t_complete *game)
{
	//get_map(argv, &game);
	//for testing:
	int width = 20	

	
	game.mlxpointer = mlx_init();
        game.winpointer = mlx_new_window(game.mlxpointer, (20 * 40),
                        (20 * 40), "solong");

}

int	get_map(char **argv, t_complete *game)
{
	char	*readmap;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		readmap = get_next_line(game->fd);
		if (!add_line(game, readmap))
			break ;
	}
	close (game->fd);
	game->widthmap = width_of_map(game->map[0]);
	return (1);
}

int main(int argc, char **argv)
{
	t_complete	game;
	
	if (argc != 2)
		return (0);
	initialize_game(argv, &game);
}
