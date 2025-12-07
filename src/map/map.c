/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:06:01 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/06 18:15:00 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_line(char *str, int y, t_line **line)
{
	t_cell	*cell;
	int		i;

	cell = NULL;
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		ft_push_cell(&cell, str[i]);
		i++;
	}
	ft_push_line(line, &cell, y);
	return (0);
}

void	map(char *arg, t_line **line)
{
	int		fd;
	char	*linebuffer;
	int		y;

	fd = open(arg, O_RDONLY);
	linebuffer = "t";
	y = 0;
	while (linebuffer != NULL)
	{
		linebuffer = get_next_line(fd);
		if (linebuffer == NULL)
			break ;
		init_line(linebuffer, y, line);
		free(linebuffer);
		y++;
	}
	close(fd);
}
