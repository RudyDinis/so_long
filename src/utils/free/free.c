/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:00:19 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/27 15:09:28 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	clear_sprite(t_anim	*a)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (a->img[i])
			mlx_destroy_image(a->mlx, a->img[i]);
		i++;
	}
	free(a);
}

void	ft_clear(t_vars *vars)
{
	t_ghost	*tmp;
	t_ghost	*p;

	p = vars->ghost;
	while (p)
	{
		tmp = p->next;
		if (p->img)
			mlx_destroy_image(vars->mlx, p->img);
		free(p);
		p = tmp;
	}
	vars->ghost = NULL;
}

void	free_0(t_vars *vars)
{
	if (!vars)
		return ;
	if (vars->map)
		free_map(vars->map);
	if (vars->animated_var)
		free(vars->animated_var);
	free(vars);
}
