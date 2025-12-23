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
    t_ghost *g = vars->ghost;
    while (g)
    {
        mlx_put_image_to_window(vars->mlx, vars->mlx_win,
            g->img, g->x, g->y);
        g = g->next;
    }
}

void	select_moove(t_vars *vars, t_ghost *current)
{
	int moved;

	moved = 0;
	while (!moved) {
		int r = rand() % 4;
		if (r == 0 && vars->map[(current->y + 31) / 31][current->x / 31] != '1') {
			current->y += 31;
			moved = 1;
		}
		if (r == 1 && vars->map[(current->y - 31) / 31][current->x / 31] != '1') {
			current->y -= 31;
			moved = 1;
		}
		if (r == 2 && vars->map[current->y / 31][(current->x + 31) / 31] != '1') {
			current->x += 31;
			moved = 1;
		}
		if (r == 3 && vars->map[current->y / 31][(current->x - 31) / 31] != '1') {
			current->x -= 31;
			moved = 1;
		}
	}
}

void	random_moove(t_vars *vars)
{
	t_ghost *current;

	current = vars->ghost;
	while (current)
	{
		select_moove(vars, current);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			current->img, current->x, current->y);
		current = current->next;
	}
}

void	init_ghost(t_vars *vars, t_ghost *ghost, int x, int y)
{
	int	w;
	int	h;

	ghost->x = x * 31;
	ghost->y = y * 31;
	ghost->moving = 0;
	ghost->dir = 0;
	ghost->step = 0;
	ghost->start_x = x * 31;
	ghost->start_y = y * 31;
	ghost->img = mlx_xpm_file_to_image(vars->mlx, "./src/textures/ghost/0.xpm", &w, &h);
	ghost->next = NULL;

	mlx_put_image_to_window(vars->mlx, vars->mlx_win, ghost->img, ghost->x, ghost->y);
}

int	setup_ghost(t_vars *vars, int x, int y)
{
	t_ghost *last = NULL;

	y = 0;
	while (y < vars->height && vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'G')
			{
				t_ghost *new_ghost = malloc(sizeof(t_ghost));
				if (!new_ghost)
				   	return (write(2, "Error\nMalloc fail\n", 19));
				init_ghost(vars, new_ghost, x, y);
				if (!vars->ghost)
					vars->ghost = new_ghost;
				else
					last->next = new_ghost;
				last = new_ghost;
			}
			x++;
		}
		y++;
	}
}
