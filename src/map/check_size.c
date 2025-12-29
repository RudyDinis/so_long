/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 19:04:46 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/29 19:44:02 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_size(t_vars *vars, char **map)
{
	int	i;

	i = 0;
	get_next_line(-1);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_1(vars);
	while (map[i])
		free(map[i++]);
	free(map);
	exit(0);
}

void	check_size(char *line, int i, t_vars *vars, char **map)
{
	int	size_x;
	int	size_y;

	mlx_get_screen_size(vars->mlx, &size_x, &size_y);
	if (i * 31 > size_y)
		free_size(vars, map);
}
