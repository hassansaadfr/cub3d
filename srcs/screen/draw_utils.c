/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:06:55 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/30 12:09:44 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void		vertical_line(int x, int y, int max_height, t_data *img)
{
	while (y < max_height)
	{
		my_mlx_pixel_put(img, x - 1, y, create_trgb(0, 0, 255, 255));
		y++;
	}

}

void		horizontal_line(int x, int y, int max_width, t_data *img)
{
	while (x < max_width)
	{
		my_mlx_pixel_put(img, x, y - 1, create_trgb(0, 0, 255, 255));
		x++;
	}
}

void		dessine_grille(t_coord size, t_coord *resolution, t_data *img)
{
	int nb_x;
	int nb_y;
	int	i;

	i = 0;
	nb_x = resolution->x / size.x;
	nb_y = resolution->y  / size.y;
	while (i <= size.x)
	{
		horizontal_line(0, nb_y * i, resolution->x, img);
		i++;
	}
	i = 0;
	while (i <= size.y)
	{
		vertical_line(nb_x * i,0, resolution->y, img);
		i++;
	}
}
