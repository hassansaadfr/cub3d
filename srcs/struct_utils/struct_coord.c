/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 21:25:54 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/26 18:56:44 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_coord		*ft_alloc_coord(int x, int y)
{
	t_coord		*coord;

	coord = malloc(sizeof(t_coord));
	coord->x = x;
	coord->y = y;
	coord->exist = 1;
	return (coord);
}

void		ft_free_coord(t_coord *coord)
{
	free(coord);
	coord = 0;
}
