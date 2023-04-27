/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassa-r <mmassa-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:11:54 by mmassa-r          #+#    #+#             */
/*   Updated: 2023/03/20 10:11:57 by mmassa-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_reader(t_solong *game, char *file)
{
	char	*tmp;
	int		i;

	i = 0;
	game->fd = open(file, O_RDONLY);
	if (game->fd == -1)
		msg_error("Couldn't open the file", game);
	while (1)
	{
		tmp = get_next_line(game->fd);
		if (!tmp)
		{
			free(tmp);
			break ;
		}
		if (game->length == 0)
			game->length = ft_strlen(tmp) - 1;
		rectangular_check(tmp, game);
		i++;
		free(tmp);
	}
	game->width = i;
	close(game->fd);
}

void	map_saver(t_solong *game, char *file)
{
	int	n_lines;

	n_lines = 0;
	game->fd = open(file, O_RDONLY);
	game->map = malloc(sizeof(char *) * (game->width));
	if (!game->map)
	{
		close(game->fd);
		msg_error("Couldn't allocate the memory inside map", game);
	}
	the_real_map_saver(game, n_lines);
	close(game->fd);
}

void	the_real_map_saver(t_solong *game, int n_lines)
{
	char	*line;
	int		index;
	char	*tmp;

	while (n_lines < game->width)
	{
		line = get_next_line(game->fd);
		if (!line)
		{
			close(game->fd);
			msg_error("Couldn't read line", game);
		}
		game->map[n_lines] = malloc(sizeof(char) * (game->length + 1));
		index = 0;
		while (index < game->length)
		{
			game->map[n_lines][index] = line[index];
			index++;
		}
		game->map[n_lines][index] = '\0';
		free(line);
		n_lines++;
	}
	tmp = get_next_line(game->fd);
	free(tmp);
}
