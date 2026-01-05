/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:25:37 by rdinis            #+#    #+#             */
/*   Updated: 2026/01/05 14:43:25 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	is_no_cross(t_vars vars, int x, int y)
{
	char	left;
	char	right;
	char	bottom;
	char	top;

	if (x == 0 || x == ft_strlen(vars.map[0]))
		return ;
	if (y == 0 || y == vars.height - 1)
		return ;
	bottom = vars.map[y + 1][x];
	right = vars.map[y][x + 1];
	left = vars.map[y][x - 1];
	top = vars.map[y - 1][x];
	if (left != '1' && right != '1' && bottom != '1' && top != '1')
		return (no_cross(vars, x * 31, y * 31));
}
