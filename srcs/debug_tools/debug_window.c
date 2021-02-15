/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 16:17:10 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/14 17:36:31 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_display_window(t_vars *mlx, char **titles, char **values)
{
	int				xspacement;
	int				yspacement;
	int				x;
	int				y;

	xspacement = 160;
	yspacement = 20;
	y = 40;
	x = 600;
	mlx_string_put(mlx->mlx, mlx->win, x, y, 0x6752d9,
		"=========[ DEBUG ]=========");
	y += yspacement;
	while (*titles)
	{
		mlx_string_put(mlx->mlx, mlx->win, x, y, 0xFFFFFF, *titles);
		mlx_string_put(mlx->mlx, mlx->win, x + xspacement, y, 0xFFFFFF, *values);
		y += yspacement;
		titles++;
		values++;
	}
}

static char	*float_to_str(float f)
{
	char	*str;

	str = malloc(sizeof(char) * 50);
	if (!str)
		return 0;
	sprintf(str, "%f", f);
	return (str);
}

void		ft_display_info(t_vars *mlx)
{
	char	*titles[8];
	char	*values[8];

	titles[0] = "player pos x   :";
	titles[1] = "player pos y   :";
	titles[2] = "player angle   :";
	titles[3] = "player pposx   :";
	titles[4] = "player pposy   :";
	titles[5] = "player delta x :";
	titles[6] = "player delta y :";
	titles[7] = 0;
	values[0] = float_to_str(mlx->c->player_pos->x);
	values[1] = float_to_str(mlx->c->player_pos->y);
	values[2] = float_to_str(mlx->player.pa);
	values[3] = float_to_str(mlx->player.p_pos.x);
	values[4] = float_to_str(mlx->player.p_pos.y);
	values[5] = float_to_str(mlx->player.pdx);
	values[6] = float_to_str(mlx->player.pdy);
	values[7] = 0;
	ft_display_window(mlx, titles, values);
	ft_display_window(mlx, titles, values);
	ft_display_window(mlx, titles, values);
}
