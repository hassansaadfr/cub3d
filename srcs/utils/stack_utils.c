/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 20:50:26 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/26 20:51:05 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int			ft_get_queue_size(t_coord **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

t_coord		*ft_get_last(t_coord **old)
{
	int		i;
	int		size;
	t_coord	*new;

	i = 0;
	size = ft_get_queue_size(old);
	new = old[size - 1];
	old[size - 1] = 0;
	return (new);
}

void		ft_free_stack(t_coord **old)
{
	int	i;

	i = 0;
	while (old && old[i])
	{
		if (old[i]->x != 0 && old[i]->y != 0 && old[i]->exist != 1)
			free(&old[i]);
		i++;
	}
	free(old);
}

t_coord		**add_to_coord_queue(t_coord **old, int x, int y)
{
	int		i;
	int		size;
	t_coord	**array;
	t_coord	*coord;

	i = 0;
	size = ft_get_queue_size(old);
	array = malloc(sizeof(t_coord) * (size + 2));
	coord = ft_alloc_coord(x, y);
	while (old && old[i])
	{
		array[i] = old[i];
		i++;
	}
	array[i++] = coord;
	array[i] = 0;
	ft_free_stack(old);
	return (array);
}
