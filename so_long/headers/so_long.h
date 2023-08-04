/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:15:54 by prossi            #+#    #+#             */
/*   Updated: 2022/12/12 20:41:55 by prossi           ###   ########.fr       */
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
# include "../minilibx/mlx.h"

typedef struct t_game
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		columncount;
	int		exitcount;
	int		x_axis;
	int		y_axis;
	int		counter;
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
void		place_images_in_game(t_gamedetails *game);
void		setup_check(t_gamedetails *game);

#endif
