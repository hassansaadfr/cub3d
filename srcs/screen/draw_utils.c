/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:06:55 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/12 18:18:42 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	if (x < 0 || y < 0)
		return ;
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
			my_mlx_pixel_put(&vars->img, j, i, BLACK);
			j++;
		}
		j = 0;
		i++;
	}
}

void		drawline(t_coord *start, int end_x, int end_y, t_vars *vars)
{
	t_coord		delta;
	t_float_pos	inc;
	int			steps;
	int			i;

	i = 0;
	delta.x = end_x - start->x;
	delta.y = end_y - start->y;
	if (abs(delta.x) > abs(delta.y))
		steps = abs(delta.x);
	else
		steps = abs(delta.y);
	inc.x = delta.x / (float) steps;
	inc.y = delta.y / (float) steps;
	float X = start->x;
	float Y = start->y;
	while (i < steps)
	{
		my_mlx_pixel_put(&vars->img, X, Y, GREEN);
		X+=inc.x;
		Y+=inc.y;
		i++;
	}
}
