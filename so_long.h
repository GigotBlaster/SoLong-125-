/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:35:18 by npetitpi          #+#    #+#             */
/*   Updated: 2023/01/26 19:08:34 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>

# define PIXEL	48
# define ESC	65307

//keyboard arrows:
# define UP		0xff52
# define DOWN	0xff54
# define LEFT	0xff51
# define RIGHT	0xff53

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		player;
	int		collectible;
	int		exit;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_image
{
	void	*player_0;
	void	*player_1;
	void	*collectible;
	void	*floor;
	void	*wall;
	void	*exit;
}	t_image;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_player	p_pos;
	int			player_x;
	int			player_y;
	t_map		map;
	t_image		img;
	int			moves;
	int			bone;
	char		dir;
}	t_data;

//error
int		ft_check_rectangle(t_data *game);
int		ft_middle_walls(t_data *game, int y);
int		ft_first_last_walls(t_data *game, int y, int x);
int		ft_check_walls(t_data *game);
int		ft_check_error(t_data *game, char *file);
int		ft_check_requirements(t_data *game);
int		ft_check_extention(const char *file);

//init & release
int		ft_init_positions(t_data *game, int i, int j);
int		ft_set_map_layout(t_data *game, char *file);
void	ft_init_map_layout(t_data *game);
void	ft_count_map_rows(t_data *game, char *file);
void	ft_set_stats(t_data *game, char *tmp);
void	ft_get_map_width(t_data *game, char *tmp);
int		ft_write_map(t_data *game, char *tmp);
void	ft_free_map(t_data *game);

//player
void	ft_move_up(t_data *game);
void	ft_move_down(t_data *game);
void	ft_move_right(t_data *game);
void	ft_move_left(t_data *game);
void	ft_move(int key, t_data *game);

//drawing
int		ft_render(t_data *game);
void	ft_create_player(t_data *game, int pixel);
void	ft_draw_map(t_data *game, int x, int y);
void	ft_open_exit(t_data *game, int pixel);
void	ft_change_player(t_data *game, int pixel, char dir);
void	ft_create_images(t_data *game);
void	ft_clear_images(t_data *game);
size_t	ft_strlen2(const char *s);

//events
int		ft_press_x(t_data *game);
int		ft_key_press(int key, t_data *game);
void	ft_game_over(t_data *game);
void	ft_check_winner(t_data *game);

//path
int		recursive(char **map_tmp, int y, int x, int *dest);
void	free_map_tmp(char **map);
int		is_map_possible_shorten(t_data *data, int *dest, int y, int x);
int		is_map_possible(t_data *data);
int		is_map_possible_shorten2(t_data *data, int *dest, int y, int x);
int		is_map_possible_shorten3(t_data *data, int *dest, int y, int x);
char	**create_map_tmp(t_data *game);
void	free_map_tmp(char **map);
int		recursive(char **map, int y, int x, int *dest);
int		recursive2(char **map, int y, int x, int *dest);

#endif
