/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:34:17 by npetitpi          #+#    #+#             */
/*   Updated: 2023/01/27 14:49:37 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	game;

	if (argc != 2)
	{
		write(2, "Error\nInvalid number of arguments.\n", 35);
		return (1);
	}
	if (ft_check_error(&game, argv[1]) < 0)
		return (2);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
	{
		write(2, "Error\nMissing graphical interface.\n", 35);
		ft_free_map(&game);
		return (4);
	}
	game.win = mlx_new_window(game.mlx, game.map.width * PIXEL, \
		game.map.height * PIXEL, "Saiko's Adventure !");
	ft_create_images(&game);
	mlx_expose_hook(game.win, &ft_render, &game);
	mlx_key_hook(game.win, ft_key_press, &game);
	mlx_hook(game.win, 17, 0, ft_press_x, &game);
	mlx_loop(game.mlx);
	return (0);
}
