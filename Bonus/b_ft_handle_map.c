/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ft_handle_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:34:42 by npetitpi          #+#    #+#             */
/*   Updated: 2023/01/26 19:15:38 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_count_map_rows(t_data *game, char *file)
{
	int		fd;
	int		rows;
	char	*line;

	rows = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		rows++;
		free(line);
	}
	game->map.height = rows;
	close(fd);
}

void	ft_set_stats(t_data *game, char *tmp)
{
	int	i;

	i = 0;
	while (tmp && tmp[i])
	{
		if (tmp[i] == 'P')
		{
			if (game->map.player == 0)
				game->map.player++;
			else
				tmp[i] = '0';
		}
		if (tmp[i] == 'T')
			game->map.trap++;
		if (tmp[i] == 'E')
			game->map.exit++;
		if (tmp[i] == 'C')
			game->map.collectible++;
		i++;
	}
}

void	ft_get_map_width(t_data *game, char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] != '\n')
	{
		game->map.width++;
		i++;
	}
}

int	ft_write_map(t_data *game, char *tmp)
{
	int	start;
	int	i;

	i = 0;
	start = 0;
	game->map.map = ft_calloc(game->map.height + 1, sizeof(char *));
	if (!(game->map.map))
		return (1);
	game->map.map[game->map.height] = 0;
	while (i < game->map.height)
	{
		if ((int)ft_strlen2(tmp + start) != game->map.width)
			return (write(1, "Error\nMap is not rectangle\n", 28), \
				ft_free_map(game), 1);
		game->map.map[i] = ft_substr(tmp, start, game->map.width);
		if (!(game->map.map[i]))
			return (1);
		i++;
		start += game->map.width + 1;
	}
	return (0);
}

void	ft_free_map(t_data *game)
{
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		free(game->map.map[y]);
		y++;
	}
	free(game->map.map);
}
