/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassa-r <mmassa-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:02:41 by mmassa-r          #+#    #+#             */
/*   Updated: 2023/04/17 16:02:52 by mmassa-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_solong *game)
{
	game->mlx.mlx_holder = mlx_init();
	if (!game->mlx.mlx_holder)
		msg_error("Couldn't iniciate mlx", game);
	game->mlx.mlx_wind = mlx_new_window(game->mlx.mlx_holder,
			game->length * TILE_SIZE, game->width * TILE_SIZE, "so_long");
	if (!game->mlx.mlx_wind)
		msg_error("Couldn't open the window", game);
}
