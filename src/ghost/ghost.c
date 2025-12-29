/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:31:11 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/20 15:57:45 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_ghosts(t_vars *vars)
{
	t_ghost	*g;

	g = vars->ghost;
	while (g)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			g->img, g->x, g->y);
		g = g->next;
	}
}

int	select_moove(t_vars *vars, t_ghost *current)
{
	int	tries;
	int	r;

	tries = 0;
	while (tries < 10)
	{
		r = rand() % 4;
		if (r == 0 && vars->map[(current->y + 31) / 31][current->x / 31] != '1')
			return (current->y += 31, 0);
		if (r == 1 && vars->map[(current->y - 31) / 31][current->x / 31] != '1')
			return (current->y -= 31, 0);
		if (r == 2 && vars->map[current->y / 31][(current->x + 31) / 31] != '1')
			return (current->x += 31, 0);
		if (r == 3 && vars->map[current->y / 31][(current->x - 31) / 31] != '1')
			return (current->x -= 31, 0);
		tries++;
	}
	return (0);
}

void	random_moove(t_vars *vars)
{
	t_ghost	*current;

	current = vars->ghost;
	while (current)
	{
		select_moove(vars, current);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			current->img, current->x, current->y);
		current = current->next;
	}
	vars->moove += 1;
}

int	init_ghost(t_vars *vars, t_ghost **last, int x, int y)
{
	int		w;
	int		h;
	t_ghost	*new_ghost;

	new_ghost = calloc(1, sizeof(t_ghost));
	if (!new_ghost)
		return (write(2, "Error\nMalloc fail\n", 19), close_hook(vars), 0);
	new_ghost->x = x * 31;
	new_ghost->y = y * 31;
	new_ghost->start_x = x * 31;
	new_ghost->start_y = y * 31;
	new_ghost->img = mlx_xpm_file_to_image(vars->mlx,
			"./src/textures/ghost/0.xpm", &w, &h);
	if (!new_ghost->img)
		return (write(1, "Error\nimage not found\n", 22), close_hook(vars), 0);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		new_ghost->img, new_ghost->x, new_ghost->y);
	if (!vars->ghost)
		vars->ghost = new_ghost;
	else
		(*last)->next = new_ghost;
	(*last) = new_ghost;
	return (0);
}

int	setup_ghost(t_vars *vars, int x, int y)
{
	t_ghost	*last;

	last = NULL;
	y = 0;
	while (y < vars->height && vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'G')
			{
				init_ghost(vars, &last, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}
