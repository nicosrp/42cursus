/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsherpa <nsherpa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:59:00 by nsherpa           #+#    #+#             */
/*   Updated: 2023/08/04 19:11:15 by nsherpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include "../minilibx/mlx.h"

typedef struct t_game
{
	int		fd;
	int		player_x;
	int		player_y;
	int		check_player;
	int		check_cols;
	int		check_door;
	int		map_height;
	int		map_width;
	int		step_counter;
	int		collectables;

	char	**map;

	void	*floor;
	void	*barrier;
	void	*player;
	void	*door;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;

}	t_gamedetails;

void		*ft_memset(void *b, int c, size_t length);
int			end_game(t_gamedetails *game);
int			get_mapdata(t_gamedetails *game, char **argv);
int			controls_working(int command, t_gamedetails *game);
void		adding_in_graphics(t_gamedetails *game);
void		match_images(t_gamedetails *game);
void		setup_check(t_gamedetails *game);
int			restricted_moving(t_gamedetails *game, int i, int j);
int			moving_updown(t_gamedetails *game, int movement);

#endif
