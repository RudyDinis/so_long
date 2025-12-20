/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_angle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:13:55 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/20 18:48:48 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	is_lefttop_wall(t_vars vars, int x, int y)
{
	char	left;
	char	top;

	left = '0';
	top = '0';
	if (x == 0 && y == 0)
		return (1);
	if (x > 0)
		left = vars.map[y][x - 1];
	if (y > 0)
		top = vars.map[y - 1][x];
	if (is_endtop(vars, x, y) == 1)
		return (0);
	if (is_endleft(vars, x, y) == 1)
		return (0);
	if (left != '1' && top != '1')
		return (1);
	return (0);
}

int	is_leftbottom_wall(t_vars vars, int x, int y)
{
	char	left;
	char	bottom;

	left = '0';
	bottom = '0';
	if (x == 0 && y == vars.height - 1)
		return (1);
	if (x > 0)
		left = vars.map[y][x - 1];
	if (y < vars.height - 1)
		bottom = vars.map[y + 1][x];
	if (is_endbottom(vars, x, y) == 1)
		return (0);
	if (is_endleft(vars, x, y) == 1)
		return (0);
	if (left != '1' && bottom != '1')
		return (1);
	return (0);
}

int	is_righttop_wall(t_vars vars, int x, int y)
{
	char	left;
	char	top;

	left = '0';
	top = '0';
	if (x == ft_strlen(vars.map[0]) - 1 && y == 0)
		return (1);
	if (x < ft_strlen(vars.map[0]) - 1)
		left = vars.map[y][x + 1];
	if (y > 0)
		top = vars.map[y - 1][x];
	if (is_endtop(vars, x, y) == 1)
		return (0);
	if (is_endright(vars, x, y) == 1)
		return (0);
	if (left != '1' && top != '1')
		return (1);
	return (0);
}

int	is_rightbottom_wall(t_vars vars, int x, int y)
{
	char	left;
	char	bottom;

	left = '0';
	bottom = '0';
	if (x == ft_strlen(vars.map[0]) - 1 && y == vars.height - 1)
		return (1);
	if (x < ft_strlen(vars.map[0]) - 1)
		left = vars.map[y][x + 1];
	if (y < vars.height - 1)
		bottom = vars.map[y + 1][x];
	if (is_endbottom(vars, x, y) == 1)
		return (0);
	if (is_endright(vars, x, y) == 1)
		return (0);
	if (left != '1' && bottom != '1')
		return (1);
	return (0);
}
