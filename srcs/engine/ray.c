/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:26:11 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/14 23:04:05 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define PI2 PI / 2
#define PI3 3 * PI / 2

typedef struct	s_ray {
	int		r;
	int		mx;
	int		my;
	int		mp;
	int		dof;
	float	rx;
	float	ry;
	float	ra;
	float	xo;
	float	yo;

	float	aTan;
	float	nTan;
}				t_ray;

void	draw_ray_lines(t_vars *v)
{
	t_ray	r;
	t_coord co;

	r.ra = v->player.pa;
	r.r = 0;
	while (r.r < 360)
	{
		// check horizontal
		r.dof = 0;
		r.aTan = -1 / tan(r.ra);
		if (r.ra > PI)
		{
			r.ry = (((int)(v->player.p_pos.y) / MAP_CUBE_SIZE) * MAP_CUBE_SIZE) - 0.0001;
			r.rx = (v->player.p_pos.y - r.ry) * r.aTan + (v->player.p_pos.x);
			r.yo = -MAP_CUBE_SIZE;
			r.xo = -r.yo * r.aTan;
		}
		if (r.ra < PI)
		{
			r.ry = (((int)(v->player.p_pos.y) / MAP_CUBE_SIZE) * MAP_CUBE_SIZE) + MAP_CUBE_SIZE;
			r.rx = ((v->player.p_pos.y) - r.ry) * r.aTan + (v->player.p_pos.x);
			r.yo = MAP_CUBE_SIZE;
			r.xo = -r.yo * r.aTan;
		}
		if (r.ra == 0 || r.ra == PI)
		{
			r.rx = v->player.p_pos.x;
			r.ry = v->player.p_pos.y;
			r.dof = 8;
		}
		while (r.dof < 8)
		{
			r.mx = ((int)(r.rx) / MAP_CUBE_SIZE);
			r.my = ((int)(r.ry) / MAP_CUBE_SIZE);
			if (r.mx > 0 && r.my > 0 && r.mx < v->map_size.x && r.my < v->map_size.y &&  v->c->map[(int)r.mx][(int)r.my] == '1')
			{
				r.dof = 8;
			}
			else
			{
				r.rx += r.xo;
				r.ry += r.yo;
				r.dof += 1;
			}
		}
		co.x = r.rx;
		co.y = r.ry;
		if (r.rx < v->c->resolution->x && r.ry < v->c->resolution->y)
			draw_cube(&co, 10, BLUE, &v->img);
		r.r++;

		// Check vertical

		r.dof = 0;
		r.nTan = -tan(r.ra);
		if (r.ra > PI2 && r.ra < PI3)
		{
			r.rx = (((int)(v->player.p_pos.x) / MAP_CUBE_SIZE) * MAP_CUBE_SIZE) - 0.0001;
			r.ry = (v->player.p_pos.x - r.rx) * r.nTan + (v->player.p_pos.y);
			r.xo = -MAP_CUBE_SIZE;
			r.yo = -r.xo * r.nTan;
		}
		if (r.ra < PI2  || r.ra > PI3)
		{
			r.rx = (((int)(v->player.p_pos.x) / MAP_CUBE_SIZE) * MAP_CUBE_SIZE) + MAP_CUBE_SIZE;
			r.ry = ((v->player.p_pos.x) - r.rx) * r.nTan + (v->player.p_pos.y);
			r.xo = MAP_CUBE_SIZE;
			r.yo = -r.xo * r.nTan;
		}
		if (r.ra == 0 || r.ra == PI)
		{
			r.rx = v->player.p_pos.x;
			r.ry = v->player.p_pos.y;
			r.dof = 8;
		}
		while (r.dof < 8)
		{
			r.mx = ((int)(r.rx) / MAP_CUBE_SIZE);
			r.my = ((int)(r.ry) / MAP_CUBE_SIZE);
			if (r.mx > 0 && r.my > 0 && r.mx <= v->map_size.x && r.my <= v->map_size.y &&  v->c->map[(int)r.mx][(int)r.my] == '1')
			{
				r.dof = 8;
			}
			else
			{
				r.rx += r.xo;
				r.ry += r.yo;
				r.dof += 1;
			}
		}
		co.x = r.rx;
		co.y = r.ry > v->player.p_pos.y ? r.ry - 64 : r.ry + 64;
		if (r.rx < v->c->resolution->x && r.ry < v->c->resolution->y)
			draw_cube(&co, 10, GREEN, &v->img);
		r.r++;
	}
	my_mlx_pixel_put(&v->img, v->player.p_pos.x , v->player.p_pos.y , GREEN);
	my_mlx_pixel_put(&v->img, v->player.p_pos.x , v->player.p_pos.y , GREEN);
	ft_draw_img(v, 0, 0);
}
