/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:31:11 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/16 15:21:43 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static unsigned long	now_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000UL + tv.tv_usec / 1000UL);
}

static int	animate_hook(void *param)
{
	t_anim			*a;
	unsigned long	now;

	a = (t_anim *)param;
	now = now_ms();
	if (now - a->last_ms >= (unsigned long)a->interval_ms)
	{
		a->frame = (a->frame + 1) % 11;
		if (a->img[a->frame])
			mlx_put_image_to_window(a->mlx, a->win, a->img[a->frame], a->x, a->y);
		a->last_ms = now;
	}
	return (0);
}

void	var(void *mlx, t_anim *a)
{
	int	w;
	int	h;

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
}

t_anim	*setup_animation(void *mlx, void *win)
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
	var(mlx, a);
	if (a->img[0])
		mlx_put_image_to_window(mlx, win, a->img[0], a->x, a->y);
	mlx_loop_hook(mlx, animate_hook, a);
	return (a);
}
