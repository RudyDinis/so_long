/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_two.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:14:02 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/27 18:17:53 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	t_cross_two(int x, int y, int size_y, int size_x)
{
	if (((x <= size_x - 25 && x >= size_x - 27)
			&& (y <= size_y - 25 || y >= size_y - 6))
		|| (x <= size_x - 4 && x >= size_x - 6
			&& (y <= size_y - 25 || y >= size_y - 6))
		|| ((y <= size_y - 25 && y >= size_y - 27)
			&& (x >= size_x - 6 || x <= size_x - 25))
		|| ((y <= size_y - 4 && y >= size_y - 6)
			&& (x >= size_x - 6 || x <= size_x - 25)))
		return (1);
	else
		return (0);
}
