/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinis <rdinis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:31:11 by rdinis            #+#    #+#             */
/*   Updated: 2025/12/20 15:57:45 by rdinis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_text(t_vars *vars)
{
	char	text[50];
	char	*score;
	char	*moove;

	score = ft_itoa(vars->score);
	moove = ft_itoa(vars->moove);
	ft_strlcpy(text, "Score: ", sizeof(text));
	ft_strlcat(text, score, sizeof(text));
	ft_strlcat(text, " Moove: ", sizeof(text));
	ft_strlcat(text, moove, sizeof(text));
	mlx_string_put(vars->mlx, vars->mlx_win,
		(ft_strlen(vars->map[0]) * 31) / 2.3, 20, 0x00FFFFFF, text);
	free(score);
	free(moove);
}
