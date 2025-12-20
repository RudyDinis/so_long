/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:59:24 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/20 18:47:52 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	is_endbottom(t_vars vars, int x, int y)
{
	char	left;
	char	right;
	char	bottom;
	char	top;

	if (x == 0 || x == ft_strlen(vars.map[0]))
		return (0);
	if (y == 0 || y == vars.height - 1)
		return (0);
	left = vars.map[y][x - 1];
	right = vars.map[y][x + 1];
	bottom = vars.map[y + 1][x];
	top = vars.map[y - 1][x];
	if (left != '1' && right != '1' && bottom != '1' && top == '1')
		return (1);
	return (0);
}

int	is_endtop(t_vars vars, int x, int y)
{
	char	left;
	char	right;
	char	top;
	char	bottom;

	if (x == 0 || x == ft_strlen(vars.map[0]))
		return (0);
	if (y == 0 || y == vars.height - 1)
		return (0);
	left = vars.map[y][x - 1];
	right = vars.map[y][x + 1];
	top = vars.map[y - 1][x];
	bottom = vars.map[y + 1][x];
	if (left != '1' && right != '1' && top != '1' && bottom == '1')
		return (1);
	return (0);
}

int	is_endleft(t_vars vars, int x, int y)
{
	char	left;
	char	right;
	char	top;
	char	bottom;

	if (x == 0 || x == ft_strlen(vars.map[0]))
		return (0);
	if (y == 0 || y == vars.height - 1)
		return (0);
	left = vars.map[y][x - 1];
	right = vars.map[y][x + 1];
	top = vars.map[y - 1][x];
	bottom = vars.map[y + 1][x];
	if (left != '1' && right == '1' && top != '1' && bottom != '1')
		return (1);
	return (0);
}

int	is_endright(t_vars vars, int x, int y)
{
	char	left;
	char	right;
	char	top;
	char	bottom;

	if (x == 0 || x == ft_strlen(vars.map[0]))
		return (0);
	if (y == 0 || y == vars.height - 1)
		return (0);
	left = vars.map[y][x - 1];
	right = vars.map[y][x + 1];
	top = vars.map[y - 1][x];
	bottom = vars.map[y + 1][x];
	if (left == '1' && right != '1' && top != '1' && bottom != '1')
		return (1);
	return (0);
}
