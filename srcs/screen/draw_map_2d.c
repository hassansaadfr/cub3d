/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 16:13:32 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/07 16:51:23 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		draw_cube(int x, int y, int color, t_data *img)
{
	int		cubsize;
	int		i;
	int		j;

	cubsize = 60;
	i = 0;
	j = 0;
	while (i < cubsize)
	{
		while (j < cubsize)
		{
			my_mlx_pixel_put(img, 0 + (cubsize * x), 0 + (cubsize * y), color);
			j++;
		}
		j = 0;
		i++;
	}
}

void			draw_2d(char **map, t_data *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '0' || ft_strrchr("NSEW", map[i][j]))
				draw_cube(i, j, create_trgb(0, 105, 0, 105), img);
			if (map[i][j] == '1')
				draw_cube(i, j, create_trgb(0, 105, 105, 105), img);
			if (map[i][j] == '2')
				draw_cube(i, j, create_trgb(0, 0, 105, 105), img);
			j++;
		}
		j = 0;
		i++;
	}
}
