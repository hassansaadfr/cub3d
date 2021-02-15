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

static void	calc_horizontal(t_ray *r, t_vars *v)
{
	r->dof = 0;
	r->atan = -1 / tan(r->ra);
	if (r->ra > PI)
	{
		r->ry = (((int)(v->player.p_pos.y) / MAP_CUBE_SIZE) * MAP_CUBE_SIZE) - 0.0001;
		r->rx = (v->player.p_pos.y - r->ry) * r->atan + (v->player.p_pos.x);
		r->yo = -MAP_CUBE_SIZE;
		r->xo = -r->yo * r->atan;
	}
	if (r->ra < PI)
	{
		r->ry = (((int)(v->player.p_pos.y) / MAP_CUBE_SIZE) * MAP_CUBE_SIZE) + MAP_CUBE_SIZE;
		r->rx = ((v->player.p_pos.y) - r->ry) * r->atan + (v->player.p_pos.x);
		r->yo = MAP_CUBE_SIZE;
		r->xo = -r->yo * r->atan;
	}
	if (r->ra == 0 || r->ra == PI)
	{
		r->rx = v->player.p_pos.x;
		r->ry = v->player.p_pos.y;
		r->dof = v->map_size.y;
	}
}

static void calc_vertical(t_ray *r, t_vars *v)
{
	r->dof = 0;
	r->ntan = -tan(r->ra);
	if (r->ra > PI / 2 && r->ra < 3 * PI / 2)
	{
		r->rx = (((int)(v->player.p_pos.x) / MAP_CUBE_SIZE) * MAP_CUBE_SIZE) - 0.0001;
		r->ry = (v->player.p_pos.x - r->rx) * r->ntan + (v->player.p_pos.y);
		r->xo = -MAP_CUBE_SIZE;
		r->yo = -r->xo * r->ntan;
	}
	if (r->ra < PI / 2  || r->ra > 3 * PI / 2)
	{
		r->rx = (((int)(v->player.p_pos.x) / MAP_CUBE_SIZE) * MAP_CUBE_SIZE) + MAP_CUBE_SIZE;
		r->ry = ((v->player.p_pos.x) - r->rx) * r->ntan + (v->player.p_pos.y);
		r->xo = MAP_CUBE_SIZE;
		r->yo = -r->xo * r->ntan;
	}
	if (r->ra == 0 || r->ra == PI)
	{
		r->rx = v->player.p_pos.x;
		r->ry = v->player.p_pos.y;
		r->dof = v->map_size.x;
	}
}

static void	horizontal_ray(t_vars *v)
{
	t_ray	r;
	t_coord co;

	r.ra = v->player.pa;
	r.r = 0;
	while (r.r < 1)
	{
		calc_horizontal(&r, v);
		while (r.dof < v->map_size.y)
		{
			r.mx = ((int)(r.rx) / MAP_CUBE_SIZE);
			r.my = ((int)(r.ry) / MAP_CUBE_SIZE);
			if (r.mx > 0 && r.my >= 0 && r.mx < v->map_size.x && r.my < v->map_size.y &&  v->c->map[(int)r.my][(int)r.mx] == '1')
				r.dof = v->map_size.y;
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
	}
}

void	vertical_ray(t_vars *v)
{
	t_ray	r;
	t_coord co;

	r.ra = v->player.pa;
	r.r = 0;
	while (r.r < 1)
	{
		calc_vertical(&r, v);
		while (r.dof < v->map_size.x)
		{
			r.mx = ((int)(r.rx) / MAP_CUBE_SIZE);
			r.my = ((int)(r.ry) / MAP_CUBE_SIZE);
			if (r.mx >= 0 && r.my > 0 && r.mx < v->map_size.x && r.my < v->map_size.y && v->c->map[(int)r.my][(int)r.mx] == '1')
				r.dof = v->map_size.x;
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
			draw_cube(&co, 10, GREEN, &v->img);
		r.r++;
	}
}

void	draw_ray_lines(t_vars *v)
{
	horizontal_ray(v);
	vertical_ray(v);
}
