/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:31:11 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/06 19:18:00 by rdinis           ###   ########.fr       */
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
		mlx_clear_window(a->mlx, a->win);
		mlx_put_image_to_window(a->mlx, a->win, a->imgs[a->frame], a->x, a->y);
		a->last_ms = now;
	}
	return (0);
}

void	var(void *mlx, t_anim *a)
{
	int	w;
	int	h;

	a->imgs[0] = mlx_xpm_file_to_image(mlx, "./src/assets/pac/5.xpm", &w, &h);
	a->imgs[1] = mlx_xpm_file_to_image(mlx, "./src/assets/pac/4.xpm", &w, &h);
	a->imgs[2] = mlx_xpm_file_to_image(mlx, "./src/assets/pac/3.xpm", &w, &h);
	a->imgs[3] = mlx_xpm_file_to_image(mlx, "./src/assets/pac/2.xpm", &w, &h);
	a->imgs[4] = mlx_xpm_file_to_image(mlx, "./src/assets/pac/1.xpm", &w, &h);
	a->imgs[5] = mlx_xpm_file_to_image(mlx, "./src/assets/pac/0.xpm", &w, &h);
	a->imgs[6] = mlx_xpm_file_to_image(mlx, "./src/assets/pac/1.xpm", &w, &h);
	a->imgs[7] = mlx_xpm_file_to_image(mlx, "./src/assets/pac/2.xpm", &w, &h);
	a->imgs[8] = mlx_xpm_file_to_image(mlx, "./src/assets/pac/3.xpm", &w, &h);
	a->imgs[9] = mlx_xpm_file_to_image(mlx, "./src/assets/pac/4.xpm", &w, &h);
	a->imgs[10] = mlx_xpm_file_to_image(mlx, "./src/assets/pac/5.xpm", &w, &h);
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
	if (a->imgs[0])
		mlx_put_image_to_window(mlx, win, a->imgs[0], a->x, a->y);
	mlx_loop_hook(mlx, animate_hook, a);
	return (a);
}
