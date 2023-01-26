/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ft_trap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:34:24 by npetitpi          #+#    #+#             */
/*   Updated: 2023/01/12 11:58:45 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_move_trap_down(t_data *game, int i)
{
	if (game->map.map[game->t_pos.y[i]][game->t_pos.x[i]] == 'P'\
	|| game->map.map[game->t_pos.y[i] + 1][game->t_pos.x[i]] == '0')
	{
		game->map.map[game->t_pos.y[i] + 1][game->t_pos.x[i]] = 'T';
		game->map.map[game->t_pos.y[i]][game->t_pos.x[i]] = '0';
		game->t_pos.y[i]++;
	}
	if (game->t_pos.y[i] == game->p_pos.y && \
	game->t_pos.x[i] == game->p_pos.x)
		ft_game_over(game);
	return (0);
}

int	ft_move_trap_left(t_data *game, int i)
{
	if (game->map.map[game->t_pos.y[i]][game->t_pos.x[i]] == 'P'\
	|| game->map.map[game->t_pos.y[i]][game->t_pos.x[i] - 1] == '0')
	{
		game->map.map[game->t_pos.y[i]][game->t_pos.x[i] - 1] = 'T';
		game->map.map[game->t_pos.y[i]][game->t_pos.x[i]] = '0';
		game->t_pos.x[i]--;
	}
	else
		ft_move_trap_down(game, i);
	if (game->t_pos.y[i] == game->p_pos.y && \
	game->t_pos.x[i] == game->p_pos.x)
		ft_game_over(game);
	return (0);
}

int	ft_move_trap_right(t_data *game, int i)
{
	if (game->map.map[game->t_pos.y[i]][game->t_pos.x[i]] == 'P'\
	|| game->map.map[game->t_pos.y[i]][game->t_pos.x[i] + 1] == '0')
	{
		game->map.map[game->t_pos.y[i]][game->t_pos.x[i] + 1] = 'T';
		game->map.map[game->t_pos.y[i]][game->t_pos.x[i]] = '0';
		game->t_pos.x[i]++;
	}
	else
		ft_move_trap_left(game, i);
	if (game->t_pos.y[i] == game->p_pos.y && \
	game->t_pos.x[i] == game->p_pos.x)
		ft_game_over(game);
	return (0);
}

int	ft_move_trap_up(t_data *game, int i)
{
	if (game->map.map[game->t_pos.y[i]][game->t_pos.x[i]] == 'P'\
	|| game->map.map[game->t_pos.y[i] - 1][game->t_pos.x[i]] == '0')
	{
		game->map.map[game->t_pos.y[i] - 1][game->t_pos.x[i]] = 'T';
		game->map.map[game->t_pos.y[i]][game->t_pos.x[i]] = '0';
		game->t_pos.y[i]--;
	}
	else
		ft_move_trap_right(game, i);
	if (game->t_pos.y[i] == game->p_pos.y && \
	game->t_pos.x[i] == game->p_pos.x)
		ft_game_over(game);
	return (0);
}

int	ft_move_trap(t_data *game)
{
	static int	x;
	int			i;

	if (x < 50000)
	{
		x++;
		return (0);
	}
	i = 0;
	while (game->t_pos.y[i])
	{
		ft_move_trap_up(game, i);
		i++;
	}
	i = 0;
	x = 0;
	return (0);
}
