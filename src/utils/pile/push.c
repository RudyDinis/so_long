/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:12:47 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/16 15:30:02 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_push_cell(t_cell **p, int val)
{
	t_cell	*element;
	t_cell	*temp;

	temp = *p;
	element = malloc(sizeof(t_cell));
	if (!element)
		write(1, "Error\nMalloc fail in ft_push\n", 29);
	element->value = val;
	element->next = NULL;
	if (!temp)
		*p = element;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = element;
	}
}

void	ft_push_line(t_line **p, t_cell **cell, int y, int x)
{
	t_line	*element;
	t_line	*temp;

	temp = *p;
	element = malloc(sizeof(t_line));
	if (!element)
		write(1, "Error\nMalloc fail in ft_push\n", 29);
	element->y = y;
	element->width = x;
	element->cells = *cell;
	element->next = NULL;
	if (!temp)
		*p = element;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = element;
	}
}
