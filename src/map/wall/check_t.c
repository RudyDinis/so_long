/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_t.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:48:03 by rdinis            #+#    #+#             */
/*   Updated: 2026/01/05 14:43:52 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	is_t_left(t_vars vars, int x, int y)
{
	char	left;
	char	right;
	char	bottom;
	char	top;

	if (y == 0 || y == vars.height - 1)
		return ;
	if (x == 0)
		left = '0';
	else
		left = vars.map[y][x - 1];
	if (x == ft_strlen(vars.map[0]))
		return ;
	right = vars.map[y][x + 1];
	bottom = vars.map[y + 1][x];
	top = vars.map[y - 1][x];
	if (left != '1' && right == '1' && bottom == '1' && top == '1')
		return (t_left(vars, x * 31, y * 31));
}

void	is_t_right(t_vars vars, int x, int y)
{
	char	left;
	char	right;
	char	bottom;
	char	top;

	if (y == 0 || y == vars.height - 1)
		return ;
	if (x == ft_strlen(vars.map[0]))
		right = '0';
	else
		right = vars.map[y][x + 1];
	if (x == 0)
		return ;
	left = vars.map[y][x - 1];
	bottom = vars.map[y + 1][x];
	top = vars.map[y - 1][x];
	if (left == '1' && right != '1' && bottom == '1' && top == '1')
		return (t_right(vars, x * 31, y * 31));
}

void	is_t_top(t_vars vars, int x, int y)
{
	char	left;
	char	right;
	char	bottom;
	char	top;

	if (x == 0 || x == ft_strlen(vars.map[0]))
		return ;
	if (y == vars.height - 1)
		return ;
	if (y == 0)
		top = '0';
	else
		top = vars.map[y - 1][x];
	right = vars.map[y][x + 1];
	left = vars.map[y][x - 1];
	bottom = vars.map[y + 1][x];
	if (left == '1' && right == '1' && bottom == '1' && top != '1')
		return (t_top(vars, x * 31, y * 31));
}

void	is_t_bottom(t_vars vars, int x, int y)
{
	char	left;
	char	right;
	char	bottom;
	char	top;

	if (x == 0 || x == ft_strlen(vars.map[0]))
		return ;
	if (y == 0)
		return ;
	if (y == vars.height - 1)
		bottom = '0';
	else
		bottom = vars.map[y + 1][x];
	right = vars.map[y][x + 1];
	left = vars.map[y][x - 1];
	top = vars.map[y - 1][x];
	if (left == '1' && right == '1' && bottom != '1' && top == '1')
		return (t_bottom(vars, x * 31, y * 31));
}

void	is_t_cross(t_vars vars, int x, int y)
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
	if (left == '1' && right == '1' && bottom == '1' && top == '1')
		return (t_cross(vars, x * 31, y * 31));
}
