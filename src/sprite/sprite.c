/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:31:11 by rdinis            #+#    #+#             */
/*   Updated: 2026/01/05 17:16:06 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static unsigned long	now_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000UL + tv.tv_usec / 1000UL);
}

int	animate_hook(t_vars	*va, t_animated_var *av)
{
	if (av->now - va->sprite->last_ms
		>= (unsigned long) va->sprite->interval_ms)
	{
		va->sprite->frame = (va->sprite->frame + 1) % 11;
		va->sprite->last_ms = av->now;
	}
	if (va->sprite->moving)
	{
		va->sprite->x += av->dx[va->sprite->dir] * av->speed;
		va->sprite->y += av->dy[va->sprite->dir] * av->speed;
		va->sprite->step += av->speed;
		if (va->sprite->step >= 31)
		{
			va->sprite->x = va->sprite->start_x + av->dx[va->sprite->dir] * 31;
			va->sprite->y = va->sprite->start_y + av->dy[va->sprite->dir] * 31;
			va->sprite->moving = 0;
			va->sprite->step = 0;
			random_moove(va);
			background(*va, va->sprite->x, va->sprite->y);
			draw_ghosts(va);
		}
	}
	mlx_put_image_to_window(va->sprite->mlx, va->sprite->win,
		va->sprite->img[va->sprite->frame], va->sprite->x, va->sprite->y);
	return (is_dead(va), 0);
}

int	animate_hook_var(void *param)
{
	t_vars			*vars;

	vars = (t_vars *)param;
	vars->animated_var->now = now_ms();
	vars->animated_var->speed = 4;
	vars->animated_var->dx[0] = -1;
	vars->animated_var->dx[1] = 1;
	vars->animated_var->dx[2] = 0;
	vars->animated_var->dx[3] = 0;
	vars->animated_var->dy[0] = 0;
	vars->animated_var->dy[1] = 0;
	vars->animated_var->dy[2] = -1;
	vars->animated_var->dy[3] = 1;
	animate_hook(vars, vars->animated_var);
	draw_text(vars);
	return (0);
}

void	var(void *mlx, t_anim *a, t_vars *vars)
{
	int	w;
	int	h;
	int	i;

	i = 0;
	a->img[0] = mlx_xpm_file_to_image(mlx, "./src/textures/pac/5.xpm", &w, &h);
	a->img[1] = mlx_xpm_file_to_image(mlx, "./src/textures/pac/4.xpm", &w, &h);
	a->img[2] = mlx_xpm_file_to_image(mlx, "./src/textures/pac/3.xpm", &w, &h);
	a->img[3] = mlx_xpm_file_to_image(mlx, "./src/textures/pac/2.xpm", &w, &h);
	a->img[4] = mlx_xpm_file_to_image(mlx, "./src/textures/pac/1.xpm", &w, &h);
	a->img[5] = mlx_xpm_file_to_image(mlx, "./src/textures/pac/0.xpm", &w, &h);
	a->img[6] = mlx_xpm_file_to_image(mlx, "./src/textures/pac/1.xpm", &w, &h);
	a->img[7] = mlx_xpm_file_to_image(mlx, "./src/textures/pac/2.xpm", &w, &h);
	a->img[8] = mlx_xpm_file_to_image(mlx, "./src/textures/pac/3.xpm", &w, &h);
	a->img[9] = mlx_xpm_file_to_image(mlx, "./src/textures/pac/4.xpm", &w, &h);
	a->img[10] = mlx_xpm_file_to_image(mlx, "./src/textures/pac/5.xpm", &w, &h);
	while (i <= 10)
	{
		if (!a->img[i])
		{
			write(1, "Error\nimage not found\n", 22);
			close_hook(vars);
		}
		i++;
	}
}

t_anim	*setup_animation(void *mlx, void *win, t_vars *vars)
{
	t_anim	*a;

	a = malloc(sizeof(*a));
	if (!a)
		return (a);
	a->mlx = mlx;
	a->win = win;
	a->frame = 0;
	a->y = 0;
	a->x = 0;
	a->interval_ms = 100;
	a->last_ms = now_ms();
	a->moving = 0;
	a->step = 0;
	var(mlx, a, vars);
	if (a->img[0])
		mlx_put_image_to_window(mlx, win, a->img[0], a->x, a->y);
	return (a);
}
