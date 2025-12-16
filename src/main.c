/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:32:36 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/16 18:46:11 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reload(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->mlx_win);
	draw_map(*vars, vars->line, vars->height);
}

int	key_clic(int keycode, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (keycode == 97)
	{
		reload(vars);
		vars->sprite->x -= 31;
	}
	else if (keycode == 100)
	{
		reload(vars);
		vars->sprite->x += 31;
	}
	else if (keycode == 119)
	{
		reload(vars);
		vars->sprite->y -= 31;
	}
	else if (keycode == 115)
	{
		reload(vars);
		vars->sprite->y += 31;
	}
	return (0);
}

int	close_hook(int keycode, void *param)
{
	t_vars	*vars;

	(void)keycode;
	vars = (t_vars *)param;
	if (vars && vars->mlx_win)
		mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_line		*line;
	int			height;

	line = NULL;
	if (argc != 2)
		return (write(2, "Error\nYou need one arg\n", 23));
	height = map(argv[1], &line);
	if (check_map(line) == -1)
		return (write(2, "Error\nMap not valid\n", 20));
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, line->width * 31, height * 31, "");
	vars.sprite = setup_animation(vars.mlx, vars.mlx_win);
	vars.height = height;
	vars.line = &line;
	setup_sprite(vars, &line);
	ft_view_line(line);
	draw_map(vars, &line, height);
	mlx_key_hook(vars.mlx_win, key_clic, &vars);
	mlx_hook(vars.mlx_win, 17, 0, close_hook, &vars);
	mlx_loop(vars.mlx);
}
