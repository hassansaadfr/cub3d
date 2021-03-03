/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 16:17:10 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/03 14:25:25 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_display_window(t_vars *mlx, char **titles, char **values)
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
	x = (MAP_CUBE_SIZE * mlx->map_size.x) + MAP_CUBE_SIZE;
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
	char	*titles[19];
	char	*values[19];
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
	titles[13] = "tex_pos      :";
	titles[14] = "draw_start   :";
	titles[15] = "dist         :";
	titles[16] = "step         :";
	titles[17] = "lineH        :";
	titles[18] = 0;

	values[0] = float_to_str(mlx->c->player_pos->x / MAP_CUBE_SIZE);
	values[1] = float_to_str(mlx->c->player_pos->y/ MAP_CUBE_SIZE);
	values[2] = float_to_str(mlx->player.pa);
	values[3] = float_to_str(mlx->player.p_pos.x);
	values[4] = float_to_str(mlx->player.p_pos.y);
	values[5] = float_to_str(mlx->player.pdx);
	values[6] = float_to_str(mlx->player.pdy);
	values[7] = ft_itoa(mlx->c->player_pos->x);
	values[8] = ft_itoa(mlx->c->player_pos->y);
	values[9] = ft_itoa(mlx->c->resolution->x);
	values[10] = ft_itoa(mlx->c->resolution->y);
	values[11] = float_to_str(mlx->player.wall.lineH);
	values[12] = float_to_str(mlx->player.wall.lineO);
	values[13] = float_to_str((float)(mlx->debug_tex_pos));
	values[14] = ft_itoa(mlx->debug_draw_start);
	values[15] = float_to_str(mlx->debug_dist);
	values[16] = float_to_str((float)mlx->debug_step);
	values[17] = float_to_str(mlx->debug_lineH);
	values[18] = 0;
	ft_display_window(mlx, titles, values);
	while (values[i])
	{
		free(values[i]);
		i++;
	}
}
