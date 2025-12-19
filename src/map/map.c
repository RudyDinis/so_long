/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:06:01 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/18 19:48:49 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_lines(char *file)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**alloc_map(int height)
{
	char	**map;

	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	map[height] = NULL;
	return (map);
}

char	**load_map(char *file, int *height)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;

	*height = count_lines(file);
	map = alloc_map(*height);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}
