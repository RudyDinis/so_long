/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:32:36 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/24 16:17:25 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moove(t_vars *vars, int dir)
{
	int	dx[4];
	int	dy[4];
	int	tx;
	int	ty;

	if (vars->sprite->moving)
		return ;
	dx[0] = -1;
	dx[1] = 1;
	dx[2] = 0;
	dx[3] = 0;
	dy[0] = 0;
	dy[1] = 0;
	dy[2] = -1;
	dy[3] = 1;
	tx = vars->sprite->x / 31 + dx[dir];
	ty = vars->sprite->y / 31 + dy[dir];
	if (vars->map[ty][tx] != '1')
	{
		vars->sprite->start_x = vars->sprite->x;
		vars->sprite->start_y = vars->sprite->y;
		vars->sprite->dir = dir;
		vars->sprite->moving = 1;
		vars->sprite->step = 0;
	}
}

void	check_eat(t_vars *vars, int dir)
{
	int	dx[4];
	int	dy[4];
	int	tx;
	int	ty;

	dx[0] = -1;
	dx[1] = 1;
	dx[2] = 0;
	dx[3] = 0;
	dy[0] = 0;
	dy[1] = 0;
	dy[2] = -1;
	dy[3] = 1;
	tx = vars->sprite->x / 31 + dx[dir];
	ty = vars->sprite->y / 31 + dy[dir];
	if (vars->map[ty][tx] != '1')
	{
		vars->moove += 1;
		random_moove(vars);
	}
	if (vars->map[ty][tx] == 'C')
	{
		vars->map[ty][tx] = '0';
		vars->score += 1;
	}
}

int	key_clic(int keycode, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (keycode == 97)
		return (check_eat(vars, 0), moove(vars, 0), 0);
	else if (keycode == 100)
		return (check_eat(vars, 1), moove(vars, 1), 0);
	else if (keycode == 119)
		return (check_eat(vars, 2), moove(vars, 2), 0);
	else if (keycode == 115)
		return (check_eat(vars, 3), moove(vars, 3), 0);
	return (0);
}

int	init(t_vars *vars, char **argv)
{
	int		height;
	char	**map;
	int		x;
	int		y;

	x = 0;
	y = 0;
	vars->map = load_map(argv[1], &height);
	vars->height = height;
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, ft_strlen(vars->map[0]) * 31,
			height * 31, "");
	vars->sprite = setup_animation(vars->mlx, vars->mlx_win);
	mlx_loop_hook(vars->mlx, animate_hook_var, vars);
	setup_sprite(vars);
	vars->img = draw_map(*vars);
	vars->score = 0;
	vars->moove = 0;
	vars->ghost = NULL;
	setup_ghost(vars, x, y);
	if (check_map(vars->map) == -1)
		return (write(2, "Error\nMap not valid\n", 20), close_hook(vars));
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc != 2)
		return (write(2, "Error\nMissing Map\n", 19));
	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (write(2, "Error\nMalloc fail\n", 19));
	vars->animated_var = malloc(sizeof(t_animated_var));
	if (!vars->animated_var)
		return (write(2, "Error\nMalloc fail\n", 19), free_0(vars), 0);
	srand(time(NULL));
	init(vars, argv);
	mlx_key_hook(vars->mlx_win, key_clic, vars);
	mlx_hook(vars->mlx_win, 17, 0, close_hook, vars);
	mlx_loop(vars->mlx);
	return (1);
}
