/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassa-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:47:53 by mmassa-r          #+#    #+#             */
/*   Updated: 2023/03/14 12:47:54 by mmassa-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	argv_checker(t_solong *game, char *argv)
{
	int	i;

	i = ft_strlen(argv) - 1;
	if (argv[i - 3] == '.' && argv[i - 2] == 'b'
		&& argv[i - 1] == 'e' && argv[i] == 'r')
		return ;
	else
		msg_error("The file is not a .ber", game);
}

int	main(int argc, char **argv)
{
	t_solong	game;

	if (argc != 2)
		msg_error("Too many or few arguments", &game);
	zero_init(&game);
	argv_checker(&game, argv[1]);
	map_reader(&game, argv[1]);
	map_saver(&game, argv[1]);
	wall_check(&game);
	valid_path(&game);
	init(&game);
	xpm_to_image(&game);
	mlx_hook(game.mlx.mlx_wind, 2, (1L << 0), key_press, &game);
	mlx_hook(game.mlx.mlx_wind, 17, (1L << 2), get_out, &game);
	mlx_loop(game.mlx.mlx_holder);
	freemap(&game);
	return (0);
}
