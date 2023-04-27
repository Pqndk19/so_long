/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassa-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:54:09 by mmassa-r          #+#    #+#             */
/*   Updated: 2023/03/14 12:54:15 by mmassa-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 36

# define W 119
# define A 97
# define S 115
# define D 100

# define A_UP 65362
# define A_DOWN 65364
# define A_LEFT 65361
# define A_RIGHT 65363

# include "mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <strings.h>
# include <stddef.h>
# include <ctype.h>
# include <fcntl.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_posi
{
	int	x;
	int	y;
}	t_posi;

typedef struct s_mlx
{
	void	*mlx_holder;
	void	*mlx_wind;
	void	*player_right;
	void	*player_left;
	void	*player_down;
	void	*player_up;
	void	*collect;
	void	*floor;
	void	*wall;
	void	*chest;
	void	*chest_open;
}	t_mlx;

typedef struct s_solong
{
	int		fd;
	int		length;
	int		width;

	char	**map;

	int		floor;
	int		wall;
	int		player;
	int		collectible;
	int		check_coll;
	int		exit;

	int		counter;

	int		exit_y;
	int		exit_x;	

	t_posi	player_pos;
	t_mlx	mlx;
}	t_solong;

void	argv_checker(t_solong *game, char *argv);
void	map_reader(t_solong *game, char *argv);
void	wall_check(t_solong *game);
void	rectangular_check(char *tmp, t_solong *game);
void	validate_check(t_solong *game);
void	utils_check(t_solong *game);
void	msg_error(char *msg, t_solong *game);
void	zero_init(t_solong *game);
void	map_saver(t_solong *game, char *file);
void	the_real_map_saver(t_solong *game, int n_lines);
void	freemap(t_solong *game);
void	valid_path(t_solong *game);
void	player_axis(t_solong *game, int y, int x);
void	utils_check_finish(t_solong *game);
void	init(t_solong *game);
void	xpm_to_image(t_solong *game);
void	xpm_to_image2(t_solong *game, int size);
void	check_img(t_solong *game);
void	img_to_wind(t_solong *game);
void	true_image_to_window(t_solong *game, int i, int j);
void	player_move(t_solong *game, int atual_y, int atual_x, int hehe);
int		key_press(int keycode, t_solong *game);
void	map_uploader(t_solong *game, int hehe);
void	upload_images(t_solong *game, int i, int j, int hehe);
void	player_img(t_solong *game, int i, int j, int hehe);
int		get_out(void *game);
void	end_of_the_world(t_solong *game);
void	destroy_img(t_solong *game);
void	count_move(t_solong *game);

#endif
