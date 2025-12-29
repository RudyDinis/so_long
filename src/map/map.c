/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:06:01 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/29 19:33:07 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_lines(char *file)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (count);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) > 1)
			count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**make_map_copy(char *file)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;
	int		height;

	height = count_lines(file);
	map = ft_calloc((size_t)(height + 1), sizeof(char *));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) > 1)
			map[i++] = ft_strtrim(line, "\n");
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}

int	count_collect(char **map)
{
	int		y;
	int		x;
	int		collectible;

	collectible = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				collectible += 1;
			x++;
		}
		y++;
	}
	return (collectible);
}

char	**load_map(char *file, int *height, t_vars *vars)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;

	*height = count_lines(file);
	if (*height == 0)
		return (write(1, "Error\nMap not valid\n", 20)
			, free_1(vars), exit(0), NULL);
	map = ft_calloc((size_t)(*height + 1), sizeof(char *));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (free_1(vars), exit(0), NULL);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) > 1)
			map[i++] = ft_strtrim(line, "\n");
		free(line);
		check_size(line, i, vars, map);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}
