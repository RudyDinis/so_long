/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:00:19 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/20 16:48:43 by rdinis           ###   ########.fr       */
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
