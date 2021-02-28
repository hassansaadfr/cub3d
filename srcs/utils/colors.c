/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 00:47:25 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/02/28 11:47:21 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
