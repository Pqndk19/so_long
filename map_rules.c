/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassa-r <mmassa-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:24:31 by mmassa-r          #+#    #+#             */
/*   Updated: 2023/03/21 14:24:34 by mmassa-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	wall_check(t_solong *game)
{
	int	i;
	int	j;
	int	len;
	int	width;

	len = game->length;
	width = game->width - 1;
	j = 0;
	while (j < len)
	{	
		if (j >= ft_strlen(game->map[0]) || game->map[0][j] != '1'
			|| game->map[width][j] != '1')
			msg_error("map is not surrounded by walls", game);
		j++;
	}
	i = 0;
	while (i <= width)
	{
		if (game->map[i][0] != '1' || game->map[i][len - 1] != '1')
			msg_error("map is not surrounded by walls", game);
		i++;
	}
	validate_check(game);
}

void	rectangular_check(char *tmp, t_solong *game)
{
	if (game->length != 0 && game->length != ((int)ft_strlen(tmp) - 1))
	{
		free(tmp);
		close(game->fd);
		msg_error("The map is not rectangular", game);
	}
}

void	validate_check(t_solong *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->width)
	{
		j = 0;
		while (j < game->length)
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1' &&
				game->map[i][j] != 'C' && game->map[i][j] != 'E' &&
				game->map[i][j] != 'P')
				msg_error("An element is missing on the map", game);
			j++;
		}
		i++;
	}
	printf("\n");
	utils_check(game);
}

void	utils_check(t_solong *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->width)
	{
		j = -1;
		while (++j < game->length)
		{
			if (game->map[i][j] == 'P')
			{
				game->player++;
				player_axis(game, i, j);
			}
			else if (game->map[i][j] == 'C')
				game->collectible++;
			else if (game->map[i][j] == 'E')
			{
				game->exit++;
				player_axis(game, i, j);
			}
		}
	}
	if (game->player != 1 || game->collectible < 1 || game->exit != 1)
		msg_error("too many elements or too few", game);
}

void	player_axis(t_solong *game, int y, int x)
{
	if (game->map[y][x] == 'P')
	{
		game->player_pos.y = y;
		game->player_pos.x = x;
	}
	else if (game->map[y][x] == 'E')
	{
		game->exit_y = y;
		game->exit_x = x;
	}
}
