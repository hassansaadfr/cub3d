/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:06:55 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/19 21:24:47 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void		ft_draw_img(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, x, y);
}

void		ft_set_bg(t_vars *vars)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < vars->c->resolution->y)
	{
		while (j < vars->c->resolution->x)
		{
			my_mlx_pixel_put(&vars->img, j, i, LIGHT_GRAY);
			j++;
		}
		j = 0;
		i++;
	}
}

void		drawline(t_coord *start, t_coord *end, int color, t_vars *vars)
{
	t_dda_line	line;
	int			i;

	i = 0;
	line.delta.x = end->x - start->x;
	line.delta.y = end->y - start->y;
	if (abs(line.delta.x) > abs(line.delta.y))
		line.steps = abs(line.delta.x);
	else
		line.steps = abs(line.delta.y);
	line.inc.x = line.delta.x / (float)line.steps;
	line.inc.y = line.delta.y / (float)line.steps;
	line.x = start->x;
	line.y = start->y;
	while (i < line.steps)
	{
		my_mlx_pixel_put(&vars->img, line.x, line.y, color);
		line.x += line.inc.x;
		line.y += line.inc.y;
		i++;
	}
}
