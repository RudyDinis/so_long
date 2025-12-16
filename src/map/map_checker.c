/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:54:20 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/16 18:59:50 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	line_length(t_cell *cell)
{
	int	len;

	len = 0;
	while (cell)
	{
		len++;
		cell = cell->next;
	}
	return (len);
}

int	check_line(t_cell *cell)
{
	while (cell)
	{
		if (cell->value != '1')
			return (-1);
		cell = cell->next;
	}
	return (1);
}

int	check_cell(char value)
{
	if (value == '0')
		return (1);
	else if (value == '1')
		return (1);
	else if (value == 'C')
		return (1);
	else if (value == 'E')
		return (1);
	else if (value == 'P')
		return (1);
	else
		return (-1);
}

int	check_side(t_cell *cell)
{
	if (!cell)
		return (-1);
	if (cell->value != '1')
		return (-1);
	while (cell->next)
	{
		if (check_cell(cell->value) == -1)
			return (-1);
		cell = cell->next;
	}
	if (cell->value != '1')
		return (-1);
	return (1);
}

int	check_map(t_line *line)
{
	int		res;
	int		len;
	int		expected_len;
	t_line	*tmp;

	res = 0;
	expected_len = -1;
	tmp = line;
	while (line && res != -1)
	{
		len = line_length(line->cells);
		if (expected_len == -1)
			expected_len = len;
		else if (len != expected_len)
			return (-1);
		if (line->y == 0 || line->next == NULL)
			res = check_line(line->cells);
		else
			res = check_side(line->cells);
		line = line->next;
	}
	if (check_condition(tmp) == -1)
		return (-1);
	return (res);
}
