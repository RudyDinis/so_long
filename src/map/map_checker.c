/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:54:20 by rdinis            #+#    #+#             */
/*   Updated: 2026/01/05 14:27:31 by rdinis           ###   ########.fr       */
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
	while (map[i] && map[i][0] != '\0')
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
	while (map[height] && map[height][0] != '\0')
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

int	check_map(char **map, char *file)
{
	int		exit;
	int		start;
	int		collect;
	char	**map_copy;

	map_copy = make_map_copy(file);
	exit = 0;
	start = 0;
	collect = 0;
	if (check_rectangular(map_copy) == -1)
		return (free_map(map_copy), -1);
	if (check_side(map_copy) == -1)
		return (free_map(map_copy), -1);
	if (check_condition(map_copy, exit, start, collect) == -1)
		return (free_map(map_copy), -1);
	if (checkpath(map_copy))
		return (free_map(map_copy), -1);
	free_map(map_copy);
	return (1);
}
