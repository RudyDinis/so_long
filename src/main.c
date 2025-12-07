/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:32:36 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/07 12:16:19 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_clic(int keycode, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (keycode == 97)
		vars->sprite->x -= 10;
	else if (keycode == 100)
		vars->sprite->x += 10;
	else if (keycode == 119)
		vars->sprite->y -= 10;
	else if (keycode == 115)
		vars->sprite->y += 10;
	mlx_clear_window(vars->mlx, vars->mlx_win);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->sprite->imgs[vars->sprite->frame],
		vars->sprite->x, vars->sprite->y);
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

	line = NULL;
	if (argc != 2)
		return (write(2, "Error\nYou need one arg\n", 23));
	map(argv[1], &line);
	if (check_map(line) == -1)
		return (write(2, "Error\nMap not valid\n", 20));
	ft_view_line(line);
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1080, 720, "Hello world!");
	vars.sprite = setup_animation(vars.mlx, vars.mlx_win);
	mlx_key_hook(vars.mlx_win, key_clic, &vars);
	mlx_hook(vars.mlx_win, 17, 0, close_hook, &vars);
	mlx_loop(vars.mlx);
}
