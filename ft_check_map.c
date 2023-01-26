/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:35:04 by npetitpi          #+#    #+#             */
/*   Updated: 2023/01/25 14:55:35 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_map_layout(t_data *game)
{
	game->map.map = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.player = 0;
	game->map.collectible = 0;
	game->map.exit = 0;
	game->moves = 0;
	game->bone = 0;
	game->dir = 'r';
}

int	ft_check_requirements(t_data *game)
{
	if (game->map.player != 1)
	{
		write(2, "Error\nNeed one player!\n", 23);
		return (-1);
	}
	if (game->map.exit != 1)
	{
		write(2, "Error\nNeed one exit!\n", 21);
		return (-1);
	}
	if (game->map.collectible < 1)
	{
		write(2, "Error\nNot enough collectibles!\n", 31);
		return (-1);
	}
	return (0);
}

int	ft_check_extention(const char *file)
{
	int	i;
	int	fd;

	i = 0;
	while (file[i])
		i++;
	while (file[i] != '.')
		i--;
	fd = open(file, __O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		return (write(2, "Error\nYou tried to open a directory\n", 36), -1);
	}
	if (ft_strncmp(&file[i], ".ber", 5) != 0)
		return (write(2, "Error\nInvalid Extention.\n", 25), -1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (write(2, "Error\nThere's no map with that name.\n", 37), -1);
	close(fd);
	return (0);
}

int	ft_set_map_layout(t_data *game, char *file)
{
	int		fd;
	int		i;
	char	*tmp;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	tmp = ft_calloc(1, 1);
	while (i < game->map.height)
	{
		line = get_next_line(fd);
		tmp = ft_strjoin_gnl(tmp, line);
		i++;
		free(line);
	}
	ft_set_stats(game, tmp);
	if (ft_check_requirements(game) < 0)
		return (close(fd), free(tmp), -1);
	ft_get_map_width(game, tmp);
	if (ft_write_map(game, tmp) == 1)
	{
		free(tmp);
		exit(1);
	}
	return (close(fd), free(tmp), 0);
}

int	ft_init_positions(t_data *game, int i, int j)
{
	while (game->map.map[i])
	{
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == 'P')
			{
				game->p_pos.x = j;
				game->p_pos.y = i;
			}
			else if (ft_strchr("1PEC0", game->map.map[i][j]) == NULL)
			{
				write(2, "Error\nInvalid input on map.\n", 28);
				return (-1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
