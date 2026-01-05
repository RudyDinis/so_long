/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_angle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:13:55 by rdinis            #+#    #+#             */
/*   Updated: 2026/01/05 14:13:21 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	is_lefttop_wall(t_vars vars, int x, int y)
{
	char	left;
	char	right;
	char	bottom;
	char	top;

	if (y == 0 && x == 0)
		return (left_top(vars, x * 31, y * 31));
	if (x == 0 || x == ft_strlen(vars.map[0]))
		return ;
	if (y == 0 || y == vars.height - 1)
		return ;
	left = vars.map[y][x - 1];
	right = vars.map[y][x + 1];
	bottom = vars.map[y + 1][x];
	top = vars.map[y - 1][x];
	if (left != '1' && right == '1' && bottom == '1' && top != '1')
		return (left_top(vars, x * 31, y * 31));
}

void	is_leftbottom_wall(t_vars vars, int x, int y)
{
	char	left;
	char	right;
	char	bottom;
	char	top;

	if (y == vars.height - 1 && x == 0)
		return (left_bottom(vars, x * 31, y * 31));
	if (x == 0 || x == ft_strlen(vars.map[0]))
		return ;
	if (y == 0 || y == vars.height - 1)
		return ;
	left = vars.map[y][x - 1];
	right = vars.map[y][x + 1];
	bottom = vars.map[y + 1][x];
	top = vars.map[y - 1][x];
	if (left != '1' && right == '1' && bottom != '1' && top == '1')
		return (left_bottom(vars, x * 31, y * 31));
}

void	is_righttop_wall(t_vars vars, int x, int y)
{
	char	left;
	char	right;
	char	bottom;
	char	top;

	if (y == 0 && x == ft_strlen(vars.map[0]) - 1)
		return (right_top(vars, x * 31, y * 31));
	if (x == 0 || x == ft_strlen(vars.map[0]))
		return ;
	if (y == 0 || y == vars.height - 1)
		return ;
	left = vars.map[y][x - 1];
	right = vars.map[y][x + 1];
	bottom = vars.map[y + 1][x];
	top = vars.map[y - 1][x];
	if (left == '1' && right != '1' && bottom == '1' && top != '1')
		return (right_top(vars, x * 31, y * 31));
}

void	is_rightbottom_wall(t_vars vars, int x, int y)
{
	char	left;
	char	right;
	char	bottom;
	char	top;

	if (y == vars.height - 1 && x == ft_strlen(vars.map[0]) - 1)
		return (right_bottom(vars, x * 31, y * 31));
	if (x == 0 || x == ft_strlen(vars.map[0]))
		return ;
	if (y == 0 || y == vars.height - 1)
		return ;
	left = vars.map[y][x - 1];
	right = vars.map[y][x + 1];
	bottom = vars.map[y + 1][x];
	top = vars.map[y - 1][x];
	if (left == '1' && right != '1' && bottom != '1' && top == '1')
		return (right_bottom(vars, x * 31, y * 31));
}
