/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassa-r <mmassa-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:42:09 by mmassa-r          #+#    #+#             */
/*   Updated: 2023/04/17 15:42:11 by mmassa-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_img(t_solong *game)
{
	mlx_destroy_image(game->mlx.mlx_holder, game->mlx.player_right);
	mlx_destroy_image(game->mlx.mlx_holder, game->mlx.player_left);
	mlx_destroy_image(game->mlx.mlx_holder, game->mlx.player_down);
	mlx_destroy_image(game->mlx.mlx_holder, game->mlx.player_up);
	mlx_destroy_image(game->mlx.mlx_holder, game->mlx.collect);
	mlx_destroy_image(game->mlx.mlx_holder, game->mlx.floor);
	mlx_destroy_image(game->mlx.mlx_holder, game->mlx.wall);
	mlx_destroy_image(game->mlx.mlx_holder, game->mlx.chest);
	mlx_destroy_image(game->mlx.mlx_holder, game->mlx.chest_open);
}

void	true_image_to_window(t_solong *game, int i, int j)
{
	if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx.mlx_holder, game->mlx.mlx_wind,
			game->mlx.floor, TILE_SIZE * j, TILE_SIZE * i);
	else if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx.mlx_holder, game->mlx.mlx_wind,
			game->mlx.wall, TILE_SIZE * j, TILE_SIZE * i);
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx.mlx_holder, game->mlx.mlx_wind,
			game->mlx.player_down, TILE_SIZE * j, TILE_SIZE * i);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx.mlx_holder, game->mlx.mlx_wind,
			game->mlx.chest, TILE_SIZE * j, TILE_SIZE * i);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx.mlx_holder, game->mlx.mlx_wind,
			game->mlx.collect, TILE_SIZE * j, TILE_SIZE * i);
}

void	img_to_wind(t_solong *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->width)
	{
		j = -1;
		while (++j < game->length)
			true_image_to_window(game, i, j);
	}
}

void	check_img(t_solong *game)
{
	if (!game->mlx.player_right)
		msg_error("player_right file error", game);
	else if (!game->mlx.player_down)
		msg_error("player_down file error", game);
	else if (!game->mlx.player_up)
		msg_error("player_up file error", game);
	else if (!game->mlx.collect)
		msg_error("collect file error", game);
	else if (!game->mlx.floor)
		msg_error("floor file error", game);
	else if (!game->mlx.wall)
		msg_error("wall file error", game);
	else if (!game->mlx.chest)
		msg_error("chest file error", game);
	else if (!game->mlx.chest_open)
		msg_error("chest_open file error", game);
	else if (!game->mlx.player_left)
		msg_error("player_left file error", game);
	img_to_wind(game);
}

void	xpm_to_image(t_solong *game)
{
	int	size;

	size = TILE_SIZE;
	game->mlx.player_right = mlx_xpm_file_to_image(game->mlx.mlx_holder,
			"./map_utils/rmov_no_feet.xpm", &size, &size);
	game->mlx.player_left = mlx_xpm_file_to_image(game->mlx.mlx_holder,
			"./map_utils/lmov_no_feet.xpm", &size, &size);
	game->mlx.player_down = mlx_xpm_file_to_image(game->mlx.mlx_holder,
			"./map_utils/fmov_no_feet.xpm", &size, &size);
	game->mlx.player_up = mlx_xpm_file_to_image(game->mlx.mlx_holder,
			"./map_utils/bmov_no_feet.xpm", &size, &size);
	game->mlx.collect = mlx_xpm_file_to_image(game->mlx.mlx_holder,
			"./map_utils/Collectible.xpm", &size, &size);
	game->mlx.floor = mlx_xpm_file_to_image(game->mlx.mlx_holder,
			"./map_utils/Floor.xpm", &size, &size);
	game->mlx.wall = mlx_xpm_file_to_image(game->mlx.mlx_holder,
			"./map_utils/Wall.xpm", &size, &size);
	game->mlx.chest = mlx_xpm_file_to_image(game->mlx.mlx_holder,
			"./map_utils/close_chest.xpm", &size, &size);
	game->mlx.chest_open = mlx_xpm_file_to_image(game->mlx.mlx_holder,
			"./map_utils/open_chest.xpm", &size, &size);
	check_img(game);
}
