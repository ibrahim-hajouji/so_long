/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:45:25 by ihajouji          #+#    #+#             */
/*   Updated: 2024/04/25 10:35:36 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	void	*image;
	int		w_height;
	int		w_width;
	int		player_x;
	int		player_y;
	int		coins_collected;
	int		num_coins;
	int		move;
	int		enemy_check;
	int		enemy_x;
	int		enemy_y;
	int		alien_x;
	int		alien_y;
	int		rand;
	int		rand2;
}			t_mlx_data;

typedef struct s_player
{
	int		x;
	int		y;
}			t_player;

char		*ft_itoa(int n);

// reading the file
int			check_file(char **av, t_mlx_data *data);
int			calculate_lines(int fd);

// checking the name of the file
void		check_name(char *str);

// checking the file
int			line(char *str);
void		check_map(char **str, int len);
int			check_valid(char c);
int			valide_path(char **s, int j, char *file, t_mlx_data *data);
int			check_enemy(char **str, int len);
int			check_cpy(char **cpy, int height, int width);
void		flood_fill(char **s, int y, int x, int j);

// calculate dimensions
int			calculate_width(t_mlx_data *data);

// player position
t_player	*player_pos(char **s, int j);

// move player
void		to_left(t_mlx_data *data);
void		to_right(t_mlx_data *data);
void		to_down(t_mlx_data *data);
void		to_up(t_mlx_data *data);

// move enemy
void		left(t_mlx_data *data);
void		right(t_mlx_data *data);
void		down(t_mlx_data *data);
void		up(t_mlx_data *data);

// image handling
void		put_image_to_map(char c, int x, int y, t_mlx_data *data);
void		put_image(t_mlx_data *data);
void		get_image(int x, int y, t_mlx_data *data, char *file);

// animation
int			turn_s(t_mlx_data *data);
int			turn_s2(t_mlx_data *data);
int			move(t_mlx_data *data);

// quitting the program in a clean way
int			ft_exit(t_mlx_data *data);
void		ft_exit2(char **s, int j, t_mlx_data *data, t_player *player);
void		ft_quit(int x);
void		_free(t_mlx_data *data, int i);

int			handle_key(int keycode, t_mlx_data *data);
int			calculate_coins(t_mlx_data *data);

#endif