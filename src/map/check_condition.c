/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_condition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:59:51 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/26 17:18:38 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill(char **tab, t_point size, int row, int col)
{
	if (row < 0 || col < 0 || row >= size.y || col >= size.x)
		return ;
	if (tab[row][col] == '1' || tab[row][col] == 'F')
		return ;

	tab[row][col] = 'F';
	fill(tab, size, row - 1, col);
	fill(tab, size, row + 1, col);
	fill(tab, size, row, col - 1);
	fill(tab, size, row, col + 1);
}

t_point	find_player(char **map)
{
	t_point	p;
	int		y;
	int		x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				p.x = x;
				p.y = y;
				return (p);
			}
			x++;
		}
		y++;
	}
	p.x = -1;
	p.y = -1;
	return (p);
}

int	exit_reachable(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	checkpath(char **map)
{
	t_point	size;
	t_point	begin;
	int		height;

	height = 0;
	while (map[height])
		height++;
	size.y = height;
	size.x = ft_strlen(map[0]);
	begin = find_player(map);
	if (begin.x == -1)
		return (0);
	fill(map, size, begin.y, begin.x);
	if (exit_reachable(map))
		return (0);

	return (1);
}

int	check_condition(char **map, int exit, int start, int collect)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				collect++;
			else if (map[y][x] == 'P')
				start++;
			else if (map[y][x] == 'E')
				exit++;
			x++;
		}
		y++;
	}
	if (exit != 1 || start != 1 || collect < 1)
		return (-1);
	return (1);
}
