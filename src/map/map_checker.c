/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:08:27 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/06 18:37:57 by rdinis           ###   ########.fr       */
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

int	check_side(t_cell *cell)
{
	if (!cell)
		return (-1);
	if (cell->value != '1')
		return (-1);
	while (cell->next)
	{
		if (cell->value != '0' && cell->value != '1'
			&& cell->value != 'C' && cell->value != 'E' && cell->value != 'P')
			return (-1);
		cell = cell->next;
	}
	if (cell->value != '1')
		return (-1);
	return (1);
}

int	check_map(t_line *line)
{
	int	res;
	int	len;
	int	expected_len;

	res = 0;
	expected_len = -1;
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
	return (res);
}
