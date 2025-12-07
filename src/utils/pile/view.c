/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:18:09 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/06 17:01:53 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_view(t_cell *p)
{
	while (p)
	{
		ft_putchar_fd(p->value, 1);
		p = p->next;
	}
}

void	ft_view_line(t_line *p)
{
	while (p)
	{
		ft_view(p->cells);
		ft_putchar_fd('\n', 1);
		p = p->next;
	}
}
