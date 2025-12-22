/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:32:36 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/22 14:11:30 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moove(t_vars *vars, int pos)
{
	if (pos == 0 && (vars->map[(vars->sprite->y / 31)]
			[(vars->sprite->x / 31) - 1] != '1'))
	{
		background(vars->img, *vars, vars->sprite->x, vars->sprite->y);
		vars->sprite->x -= 31;
	}
	if (pos == 1 && (vars->map[(vars->sprite->y / 31)]
			[(vars->sprite->x / 31) + 1] != '1'))
	{
		background(vars->img, *vars, vars->sprite->x, vars->sprite->y);
		vars->sprite->x += 31;
	}
	if (pos == 2 && (vars->map[(vars->sprite->y / 31) - 1]
			[vars->sprite->x / 31] != '1'))
	{
		background(vars->img, *vars, vars->sprite->x, vars->sprite->y);
		vars->sprite-> y -= 31;
	}
	if (pos == 3 && (vars->map[(vars->sprite->y / 31) + 1]
			[vars->sprite->x / 31] != '1'))
	{
		background(vars->img, *vars, vars->sprite->x, vars->sprite->y);
		vars->sprite->y += 31;
	}
}

int	key_clic(int keycode, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (keycode == 97)
		moove(vars, 0);
	else if (keycode == 100)
		moove(vars, 1);
	else if (keycode == 119)
		moove(vars, 2);
	else if (keycode == 115)
		moove(vars, 3);
	return (0);
}

int	close_hook(void *param)
{
	t_vars	*vars;

	vars = param;
	mlx_loop_end(vars->mlx);
	if (vars->sprite)
		clear_sprite(vars->sprite);
	if (vars->img.img)
		mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_map(vars->map);
	free(vars);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;
	int		height;
	char	**map;

	if (argc != 2)
		return (write(2, "Error\nYou need one arg\n", 23));
	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (1);
	vars->map = load_map(argv[1], &height);
	vars->height = height;
	if (check_map(vars->map) == -1)
		return (write(2, "Error\nMap not valid\n", 20));
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, ft_strlen(vars->map[0]) * 31,
			height * 31, "");
	vars->sprite = setup_animation(vars->mlx, vars->mlx_win);
	setup_sprite(*vars);
	vars->img = draw_map(*vars);
	mlx_key_hook(vars->mlx_win, key_clic, vars);
	mlx_hook(vars->mlx_win, 17, 0, close_hook, vars);
	mlx_loop(vars->mlx);
}
