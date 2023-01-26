/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ft_path2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:10:02 by npetitpi          #+#    #+#             */
/*   Updated: 2023/01/26 19:10:32 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**create_map_tmp(t_data *game)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_calloc(game->map.height + 1, sizeof(char *));
	if (!tmp)
		return (NULL);
	while (i < game->map.height)
	{
		tmp[i] = ft_strdup(game->map.map[i]);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

void	free_map_tmp(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	recursive(char **map, int y, int x, int *dest)
{
	map[y][x] = '1';
	if (y == dest[0] && x == dest[1])
		return (1);
	if (map[y][x - 1] != '1')
		if (recursive(map, y, x - 1, dest))
			return (1);
	if (map[y - 1][x] != '1')
		if (recursive(map, y - 1, x, dest))
			return (1);
	if (map[y][x + 1] != '1')
		if (recursive(map, y, x + 1, dest))
			return (1);
	if (map[y + 1][x] != '1')
		if (recursive(map, y + 1, x, dest))
			return (1);
	return (0);
}

int	recursive2(char **map, int y, int x, int *dest)
{
	map[y][x] = '1';
	if (y == dest[0] && x == dest[1])
		return (1);
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'E')
		if (recursive2(map, y, x - 1, dest))
			return (1);
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'E')
		if (recursive2(map, y - 1, x, dest))
			return (1);
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'E')
		if (recursive2(map, y, x + 1, dest))
			return (1);
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'E')
		if (recursive2(map, y + 1, x, dest))
			return (1);
	return (0);
}
