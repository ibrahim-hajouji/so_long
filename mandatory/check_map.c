/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 02:27:35 by ihajouji          #+#    #+#             */
/*   Updated: 2024/04/21 12:37:03 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(char **str, int len)
{
	int	i;

	i = 0;
	while (str[0][i] != '\n')
	{
		if (str[0][i] != '1' || str[len - 1][i] != '1')
			ft_quit(6);
		i++;
	}
	i = 0;
	while (i < len)
	{
		if (str[i][0] != '1' || str[i][line(str[0]) - 1] != '1')
			ft_quit(6);
		i++;
	}
	return ;
}

void	check_rectangle(char **str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if ((line(str[i]) != line(str[0])))
			ft_quit(5);
		i++;
	}
	return ;
}

void	check_char(int c, int e, int p)
{
	if (e > 1 || e == 0)
		ft_quit(0);
	if (p > 1 || p == 0)
		ft_quit(1);
	if (c == 0)
		ft_quit(4);
	return ;
}

void	check_valable(char **str, int len, int c, int e)
{
	int	i;
	int	k;
	int	p;

	i = 0;
	p = 0;
	while (i < len)
	{
		k = 0;
		while (k < line(str[0]))
		{
			if (str[i][k] == 'E')
				e++;
			else if (str[i][k] == 'P')
				p++;
			else if (str[i][k] == 'C')
				c++;
			else if (check_char2(str[i][k]) == 0)
				ft_quit(3);
			k++;
		}
		i++;
	}
	check_char(c, e, p);
	return ;
}

void	check_map(char **str, int len)
{
	int	e;
	int	c;

	e = 0;
	c = 0;
	check_valable(str, len, c, e);
	check_rectangle(str, len);
	check_walls(str, len);
}
