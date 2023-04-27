/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_uploader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassa-r <mmassa-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:32:05 by mmassa-r          #+#    #+#             */
/*   Updated: 2023/04/26 10:32:11 by mmassa-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_move(t_solong *game)
{
	char	*move;

	game->counter++;
	move = ft_itoa(game->counter);
	ft_putstr_fd("Moves: ", 1);
	ft_putstr_fd(move, 1);
	ft_putstr_fd("\n", 1);
	mlx_string_put(game->mlx.mlx_holder, game->mlx.mlx_wind,
		50, 75, 0x00000000, "Move: ");
	mlx_string_put(game->mlx.mlx_holder, game->mlx.mlx_wind,
		80, 75, 0x00000000, move);
	free(move);
}

void	player_img(t_solong *game, int i, int j, int hehe)
{
	if (hehe == 1)
		mlx_put_image_to_window(game->mlx.mlx_holder, game->mlx.mlx_wind,
			game->mlx.player_up, TILE_SIZE * j, TILE_SIZE * i);
	else if (hehe == 2)
		mlx_put_image_to_window(game->mlx.mlx_holder, game->mlx.mlx_wind,
			game->mlx.player_left, TILE_SIZE * j, TILE_SIZE * i);
	else if (hehe == 3)
		mlx_put_image_to_window(game->mlx.mlx_holder, game->mlx.mlx_wind,
			game->mlx.player_down, TILE_SIZE * j, TILE_SIZE * i);
	else if (hehe == 4)
		mlx_put_image_to_window(game->mlx.mlx_holder, game->mlx.mlx_wind,
			game->mlx.player_right, TILE_SIZE * j, TILE_SIZE * i);
}

void	upload_images(t_solong *game, int i, int j, int hehe)
{
	if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx.mlx_holder, game->mlx.mlx_wind,
			game->mlx.floor, TILE_SIZE * j, TILE_SIZE * i);
	else if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx.mlx_holder, game->mlx.mlx_wind,
			game->mlx.wall, TILE_SIZE * j, TILE_SIZE * i);
	else if (game->map[i][j] == 'E' && game->collectible != 0)
		mlx_put_image_to_window(game->mlx.mlx_holder, game->mlx.mlx_wind,
			game->mlx.chest, TILE_SIZE * j, TILE_SIZE * i);
	else if (game->map[i][j] == 'E' && game->collectible == 0)
		mlx_put_image_to_window(game->mlx.mlx_holder, game->mlx.mlx_wind,
			game->mlx.chest_open, TILE_SIZE * j, TILE_SIZE * i);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx.mlx_holder, game->mlx.mlx_wind,
			game->mlx.collect, TILE_SIZE * j, TILE_SIZE * i);
	else if (game->map[i][j] == 'P')
		player_img(game, i, j, hehe);
}

void	map_uploader(t_solong *game, int hehe)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->width)
	{
		j = 0;
		while (j < game->length)
		{
			upload_images(game, i, j, hehe);
			j++;
		}
		i++;
	}
	count_move(game);
}
