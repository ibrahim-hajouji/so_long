/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:32:20 by ihajouji          #+#    #+#             */
/*   Updated: 2024/04/23 15:49:34 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood_fill(char **s, int y, int x, int j)
{
	int	len;

	len = ft_strlen(s[0]) - 1;
	if (x < 0 || y >= j || y < 0 || x >= len)
		return ;
	if (s[y][x] == '1')
		return ;
	s[y][x] = '1';
	flood_fill(s, y + 1, x, j);
	flood_fill(s, y - 1, x, j);
	flood_fill(s, y, x + 1, j);
	flood_fill(s, y, x - 1, j);
}

int	check_cpy(char **cpy, int height, int width)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (cpy[y][x] != '0' && cpy[y][x] != '1' && cpy[y][x] != 'S')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	valide_path(char **s, int j, char *file, t_mlx_data *data)
{
	char		**cpy;
	int			i;
	int			len;
	int			fd;
	t_player	*player;

	i = 0;
	cpy = malloc(sizeof(char *) * j);
	if (!cpy)
		ft_quit(-1);
	len = ft_strlen(s[0]) - 1;
	fd = open(file, O_RDONLY);
	while (i < j)
		cpy[i++] = get_next_line(fd);
	close(fd);
	player = player_pos(s, j);
	flood_fill(cpy, player->y, player->x, j);
	if (check_cpy(cpy, j, len) == 0)
		ft_exit2(cpy, j, data, player);
	i = j - 1;
	while (i >= 0)
		free(cpy[i--]);
	free(cpy);
	free(player);
	return (1);
}

int	calculate_lines(int fd)
{
	char	*str;
	int		j;

	j = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		free(str);
		j++;
	}
	return (j);
}

int	check_file(char **av, t_mlx_data *data)
{
	int	i;
	int	j;
	int	fd;

	i = 0;
	j = 0;
	check_name(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n File not found\n");
		exit(0);
	}
	j = calculate_lines(fd);
	close(fd);
	fd = open(av[1], O_RDONLY);
	data->map = malloc(sizeof(char *) * j);
	if (!data->map)
		exit(0);
	while (i < j)
		data->map[i++] = get_next_line(fd);
	close(fd);
	check_map(data->map, j);
	valide_path(data->map, j, av[1], data);
	return (j);
}
