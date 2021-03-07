/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 16:17:10 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/07 21:37:04 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_debug_to_window(t_vars *mlx, char **titles, char **values)
{
	int				xspacement;
	int				yspacement;
	int				x;
	int				y;

	if (!DEBUG)
		return ;
	xspacement = 160;
	yspacement = 20;
	y = 40;
	x = (TILE_SIZE * mlx->map_size.x) + TILE_SIZE;
	mlx_string_put(mlx->mlx, mlx->win, x, y, 0x6752d9,
		"=========[ DEBUG ]=========");
	y += yspacement;
	while (*titles)
	{
		mlx_string_put(mlx->mlx, mlx->win, x, y, BLACK, *titles);
		mlx_string_put(mlx->mlx, mlx->win, x + xspacement, y, BLACK, *values);
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
		return (0);
	sprintf(str, "%f", f);
	return (str);
}

void		ft_display_info(t_vars *mlx)
{
	char	*titles[14];
	char	*values[14];
	int		i;

	i = 0;
	titles[0] = "player pos x   :";
	titles[1] = "player pos y   :";
	titles[2] = "player angle   :";
	titles[3] = "player pposx px:";
	titles[4] = "player pposy px:";
	titles[5] = "player delta x :";
	titles[6] = "player delta y :";
	titles[7] = "player x:";
	titles[8] = "player y:";
	titles[9] = "resolution x :";
	titles[10] = "resolution y :";
	titles[11] = "wall height y:";
	titles[12] = "wall offset  :";
	titles[13] = 0;
	values[0] = float_to_str(mlx->c->player_pos->x / TILE_SIZE);
	values[1] = float_to_str(mlx->c->player_pos->y / TILE_SIZE);
	values[2] = float_to_str(mlx->player.pa);
	values[3] = float_to_str(mlx->player.p_pos.x);
	values[4] = float_to_str(mlx->player.p_pos.y);
	values[5] = float_to_str(mlx->player.pdx);
	values[6] = float_to_str(mlx->player.pdy);
	values[7] = ft_itoa(mlx->c->player_pos->x);
	values[8] = ft_itoa(mlx->c->player_pos->y);
	values[9] = ft_itoa(mlx->c->resolution->x);
	values[10] = ft_itoa(mlx->c->resolution->y);
	values[11] = float_to_str(mlx->player.wall.line_h);
	values[12] = float_to_str(mlx->player.wall.line_o);
	values[13] = 0;
	print_debug_to_window(mlx, titles, values);
	while (values[i])
	{
		free(values[i]);
		i++;
	}
}
