/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassa-r <mmassa-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:43:12 by mmassa-r          #+#    #+#             */
/*   Updated: 2023/03/20 15:43:15 by mmassa-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_of_the_world(t_solong *game)
{
	destroy_img(game);
	mlx_destroy_window(game->mlx.mlx_holder, game->mlx.mlx_wind);
	mlx_destroy_display(game->mlx.mlx_holder);
	free(game->mlx.mlx_holder);
	freemap(game);
	exit(0);
}

void	freemap(t_solong *game)
{
	int	i;

	i = 0;
	while (i < game->width)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	msg_error(char *msg, t_solong *game)
{
	ft_putstr_fd("ERROR: ", 1);
	ft_putstr_fd(msg, 1);
	ft_putstr_fd("\n", 1);
	if (game->map)
		freemap(game);
	exit(1);
}

void	zero_init(t_solong *game)
{
	game->fd = 0;
	game->length = 0;
	game->width = 0;
	game->map = NULL;
	game->floor = 0;
	game->wall = 0;
	game->player = 0;
	game->collectible = 0;
	game->check_coll = 0;
	game->exit = 0;
	game->exit_y = 0;
	game->exit_x = 0;
	game->player_pos.x = 0;
	game->player_pos.y = 0;
	game->counter = 0;
	game->player_pos.y = 0;
	game->player_pos.x = 0;
}
