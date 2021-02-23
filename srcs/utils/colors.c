/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 00:47:25 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/23 21:37:50 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

static int	get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

static int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int			create_color(t_color *c)
{
	int	color;

	color = create_trgb(c->a, c->r, c->g, c->b);
	return (color);
}

int			add_shade(double shade, int color)
{
	int		r;
	int		g;
	int		b;
	int		t;
	int		out;

	t = (((int)(shade * (double)100) * 2.55));
	r = get_r(color);
	g = get_g(color);
	b = get_b(color);
	out = create_trgb(t, r, g, b);
	return (out);
}
