/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ft_handle_trap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:34:37 by npetitpi          #+#    #+#             */
/*   Updated: 2023/01/26 19:15:56 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_set_traps(t_data *game)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	j = 0;
	z = 0;
	while (game->map.map[i] && z < game->map.trap)
	{
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == 'T')
			{
				game->t_pos.x[z] = j;
				game->t_pos.y[z] = i;
				z++;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	ft_init_traps(t_data *game)
{
	game->t_pos.x = malloc((game->map.trap + 1) * sizeof(int));
	game->t_pos.y = malloc((game->map.trap + 1) * sizeof(int));
	if (!game->t_pos.x || !game->t_pos.y)
	{
		if (game->t_pos.x)
			free(game->t_pos.x);
		if (game->t_pos.y)
			free(game->t_pos.y);
		return (-1);
	}
	game->t_pos.x[game->map.trap] = 0;
	game->t_pos.y[game->map.trap] = 0;
	ft_set_traps(game);
	return (0);
}

int	ft_trap_anim(t_data *game)
{
	static int	x;
	int			pixel;

	pixel = PIXEL;
	if (x <= 20000)
	{
		if (x == 10000)
		{
			mlx_destroy_image(game->mlx, game->img.trap);
			game->img.trap = mlx_xpm_file_to_image(game->mlx, \
			"./Bonus/sprites_bonus/Trap_1.xpm", &pixel, &pixel);
			ft_render(game);
		}
		else if (x == 20000)
		{
			mlx_destroy_image(game->mlx, game->img.trap);
			game->img.trap = mlx_xpm_file_to_image(game->mlx, \
				"./Bonus/sprites_bonus/Trap_1.xpm", &pixel, &pixel);
			ft_render(game);
			x = 0;
		}
		x++;
	}
	ft_move_trap(game);
	return (0);
}

void	ft_free_traps(t_data *game)
{
	free(game->t_pos.y);
	free(game->t_pos.x);
}
