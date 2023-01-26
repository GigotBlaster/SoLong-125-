/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:34:48 by npetitpi          #+#    #+#             */
/*   Updated: 2023/01/25 12:47:46 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_change_player(t_data *game, int pixel, char dir)
{
	if (dir == 'r')
	{
		mlx_destroy_image(game->mlx, game->img.player_0);
		game->img.player_0 = mlx_xpm_file_to_image(game->mlx, \
			"./sprites/Saiko_0.xpm", &pixel, &pixel);
		mlx_destroy_image(game->mlx, game->img.player_1);
		game->img.player_1 = mlx_xpm_file_to_image(game->mlx, \
			"./sprites/Saiko_1.xpm", &pixel, &pixel);
	}
	else if (dir == 'l')
	{
		mlx_destroy_image(game->mlx, game->img.player_0);
		game->img.player_0 = mlx_xpm_file_to_image(game->mlx, \
			"./sprites/Saiko_2.xpm", &pixel, &pixel);
		mlx_destroy_image(game->mlx, game->img.player_1);
		game->img.player_1 = mlx_xpm_file_to_image(game->mlx, \
			"./sprites/Saiko_3.xpm", &pixel, &pixel);
	}
}

void	ft_create_images(t_data *game)
{
	int	pixel;

	pixel = PIXEL;
	game->img.floor = mlx_xpm_file_to_image(game->mlx, "./sprites/Floor.xpm", \
		&pixel, &pixel);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "./sprites/Wall.xpm", \
		&pixel, &pixel);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/Bone.xpm", &pixel, &pixel);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/Exit.xpm", &pixel, &pixel);
	ft_create_player(game, pixel);
}

void	ft_create_player(t_data *game, int pixel)
{
	game->img.player_0 = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/Saiko_0.xpm", &pixel, &pixel);
	game->img.player_1 = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/Saiko_1.xpm", &pixel, &pixel);
}

void	ft_clear_images(t_data *game)
{
	mlx_destroy_image(game->mlx, game->img.player_0);
	mlx_destroy_image(game->mlx, game->img.player_1);
	mlx_destroy_image(game->mlx, game->img.floor);
	mlx_destroy_image(game->mlx, game->img.collectible);
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_image(game->mlx, game->img.exit);
}
