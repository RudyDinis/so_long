/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_condition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:59:51 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/16 19:00:11 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_condition(t_line *line)
{
	t_vars_map	vars;
	t_cell		*cell;

	vars.p = 0;
	vars.e = 0;
	vars.c = 0;
	while (line)
	{
		cell = line->cells;
		while (cell->next)
		{
			if (cell->value == 'C')
				vars.c++;
			else if (cell->value == 'E')
				vars.e++;
			else if (cell->value == 'P')
				vars.p++;
			cell = cell->next;
		}
		line = line->next;
	}
	if (vars.p != 1 || vars.e != 1 || vars.c != 1)
		return (-1);
	return (1);
}
