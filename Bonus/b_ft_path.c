/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ft_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:35:30 by npetitpi          #+#    #+#             */
/*   Updated: 2023/01/26 19:10:34 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_map_possible_shorten(t_data *data, int *dest, int y, int x)
{
	char	**map_tmp;

	map_tmp = create_map_tmp(data);
	dest[0] = y;
	dest[1] = x;
	if (!recursive(map_tmp, data->p_pos.y, data->p_pos.x, dest))
		return (free(dest), free_map_tmp(map_tmp), 0);
	free_map_tmp(map_tmp);
	return (1);
}

int	is_map_possible_shorten2(t_data *data, int *dest, int y, int x)
{
	char	**map_tmp;

	map_tmp = create_map_tmp(data);
	dest[0] = y;
	dest[1] = x;
	if (!recursive2(map_tmp, data->p_pos.y, data->p_pos.x, dest))
		return (free(dest), free_map_tmp(map_tmp), 0);
	free_map_tmp(map_tmp);
	return (1);
}

int	is_map_possible(t_data *data)
{
	int		y;
	int		x;
	int		*dest;

	y = 0;
	dest = ft_calloc(2, sizeof(int));
	if (!dest)
		return (0);
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (!is_map_possible_shorten3(data, dest, y, x))
				return (0);
			x++;
		}
		y++;
	}
	return (free(dest), 1);
}

int	is_map_possible_shorten3(t_data *data, int *dest, int y, int x)
{
	if (data->map.map[y][x] == 'C')
	{
		if (!is_map_possible_shorten2(data, dest, y, x))
			return (0);
	}
	if (data->map.map[y][x] == 'E')
	{
		if (!is_map_possible_shorten(data, dest, y, x))
			return (0);
	}
	return (1);
}
