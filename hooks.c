/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassa-r <mmassa-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:36:33 by mmassa-r          #+#    #+#             */
/*   Updated: 2023/04/20 13:36:34 by mmassa-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move(t_solong *game, int atual_y, int atual_x, int hehe)
{
	int	last_py;
	int	last_px;

	last_py = game->player_pos.y;
	last_px = game->player_pos.x;
	if (game->map[atual_y][atual_x] == 'E' && game->collectible == 0)
	{
		count_move(game);
		ft_putstr_fd("LADIES AND GENTLEMEN... WE HAVE A WINNER\n", 1);
		end_of_the_world(game);
	}
	else if (game->map[atual_y][atual_x] != '1')
	{
		game->map[last_py][last_px] = '0';
		if (game->map[atual_y][atual_x] == 'C')
			game->collectible--;
		game->player_pos.y = atual_y;
		game->player_pos.x = atual_x;
		game->map[atual_y][atual_x] = 'P';
		if (game->map[game->exit_y][game->exit_x] != 'P')
			game->map[game->exit_y][game->exit_x] = 'E';
		map_uploader(game, hehe);
	}
}

int	key_press(int keycode, t_solong *game)
{
	if (keycode == W || keycode == A_UP)
		player_move(game, game->player_pos.y - 1, game->player_pos.x, 1);
	else if (keycode == A || keycode == A_LEFT)
		player_move(game, game->player_pos.y, game->player_pos.x - 1, 2);
	else if (keycode == S || keycode == A_DOWN)
		player_move(game, game->player_pos.y + 1, game->player_pos.x, 3);
	else if (keycode == D || keycode == A_RIGHT)
		player_move(game, game->player_pos.y, game->player_pos.x + 1, 4);
	else if (keycode == 65307)
		end_of_the_world(game);
	return (0);
}

int	get_out(void *game)
{
	end_of_the_world(game);
	return (0);
}
