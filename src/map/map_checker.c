/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:54:20 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/18 19:43:39 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


int	check_cell(char value)
{
	if (value == '0')
		return (1);
	else if (value == '1')
		return (1);
	else if (value == 'C')
		return (1);
	else if (value == 'E')
		return (1);
	else if (value == 'P')
		return (1);
	else
		return (-1);
}

int	check_rectangular(char **map)
{
	int	i;
	int	len;

	len = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != len)
			return (-1);
		i++;
	}
	return (1);
}

int	check_side(char **map)
{
	int	x;
	int	y;
	int	height;
	int	width;

	x = 0;
	y = 1;
	height = 0;
	while (map[height])
		height++;
	width = ft_strlen(map[0]);
	while (x < width)
	{
		if (map[0][x] != '1' || map[height - 1][x] != '1')
			return (-1);
		x++;
	}
	while (y < height)
	{
		if (map[y][0] != '1' || map[y][width - 1] != '1')
			return (-1);
		y++;
	}
	return (1);
}

int	check_map(char **map)
{
	if (check_rectangular(map) == -1)
		return (-1);
	if (check_side(map) == -1)
		return (-1);
}
