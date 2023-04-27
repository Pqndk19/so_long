/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassa-r <mmassa-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:30:30 by mmassa-r          #+#    #+#             */
/*   Updated: 2023/04/12 14:30:37 by mmassa-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(t_solong *game, t_posi pos, char **map_clone)
{	
	if ((pos.x < 0 || pos.x >= game->length)
		|| (pos.y < 0 || pos.y >= game->width)
		|| map_clone[pos.y][pos.x] == '1')
		return (0);
	else if (map_clone[pos.y][pos.x] == 'C')
		game->check_coll++;
	else if (map_clone[pos.y][pos.x] == 'E')
		game->exit = 1;
	map_clone[pos.y][pos.x] = '1';
	flood_fill(game, (t_posi){pos.x + 1, pos.y}, map_clone);
	flood_fill(game, (t_posi){pos.x - 1, pos.y}, map_clone);
	flood_fill(game, (t_posi){pos.x, pos.y + 1}, map_clone);
	flood_fill(game, (t_posi){pos.x, pos.y - 1}, map_clone);
	if (game->check_coll == game->collectible)
		return (game->exit);
	return (0);
}

void	valid_path(t_solong *game)
{
	char	**map_clone;
	int		i;

	i = 0;
	map_clone = malloc(sizeof(char *) * game->width);
	while (i < game->width)
	{
		map_clone[i] = ft_strdup(game->map[i]);
		if (!map_clone[i])
		{
			while (i--)
				free(map_clone[i]);
			free(map_clone);
		}
		i++;
	}
	if (flood_fill(game, game->player_pos, map_clone) == 0)
	{
		free(map_clone);
		msg_error("Couldn't find a valide path", game);
	}
	i = -1;
	while (++i < game->width)
		free(map_clone[i]);
	free(map_clone);
}
