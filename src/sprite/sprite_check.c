/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:31:43 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/24 13:32:54 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	is_dead(t_vars	*vars)
{
	t_ghost	*g;
	int		sx;
	int		sy;
	int		gx;
	int		gy;

	g = vars->ghost;
	while (g)
	{
		sx = vars->sprite->x / 31;
		sy = vars->sprite->y / 31;
		gx = g->x / 31;
		gy = g->y / 31;
		if (sx == gx && sy == gy)
			close_hook(vars);
		g = g->next;
	}
}
