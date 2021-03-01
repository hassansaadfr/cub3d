/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 14:49:17 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/01 14:49:54 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		get_map_dimensions(t_vars *vars)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	while (vars->c->map[y])
	{
		while (vars->c->map[y][i])
			i++;
		if (i > x)
			x = i;
		i = 0;
		y++;
	}
	vars->map_size.x = x;
	vars->map_size.y = y;
}

t_coord		*get_screen_size(void *mlx, t_coord *res)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_get_screen_size(mlx, &x, &y);
	if (res->x > x)
		res->x = x;
	if (res->y > y)
		res->y = y;
	return (res);
}

void		init_keys_struct(t_vars *v)
{
	v->keys.north = 0;
	v->keys.south = 0;
	v->keys.east = 0;
	v->keys.west = 0;
}
