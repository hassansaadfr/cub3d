/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 03:55:03 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/27 03:06:21 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int		ft_should_be_treated(int x, int y, char **map)
{
	int	height;

	height = get_array_size(map);
	if (x < 0 || y < 0 || y >= height || x >= (int)ft_strlen(map[y]))
	{
		return (-1);
	}
	if (map[y][x] == '1')
		return (0);
	if (map[y][x] == '0' || map[y][x] == '2')
	{
		map[y][x] = 'X';
		return (1);
	}
	if (map[y][x] == ' ')
		return (-1);
	return (map[y][x] == '0' || map[y][x] == '2');
}

int				ft_clean_stack(int err, t_coord *p, t_coord **stack, char **map)
{
	int		i;

	i = 0;
	if (err == -1)
	{
		free(p);
		p = 0;
	}
	while (stack[i])
	{
		free(stack[i]);
		i++;
	}
	free(stack);
	ft_read_array_str(map);
	free_array_str(map);
	if (err == -1)
		return (-1);
	return (1);
}

int				ft_flood_fill(t_coord *player_pos, char **original)
{
	t_coord	**stack;
	t_coord	*p;
	char	**map;
	int		err;

	err = 0;
	map = ft_copy_arr(original);
	stack = 0;
	stack = add_to_coord_queue(stack, player_pos->x, player_pos->y);
	while (ft_get_queue_size(stack) > 0 && err != -1)
	{
		p = ft_get_last(stack);
		if ((err = ft_should_be_treated(p->x - 1, p->y, map)))
			stack = add_to_coord_queue(stack, p->x - 1, p->y);
		if ((err = ft_should_be_treated(p->x, p->y - 1, map)))
			stack = add_to_coord_queue(stack, p->x, p->y - 1);
		if ((err = ft_should_be_treated(p->x, p->y + 1, map)))
			stack = add_to_coord_queue(stack, p->x, p->y + 1);
		if ((err = ft_should_be_treated(p->x + 1, p->y, map)))
			stack = add_to_coord_queue(stack, p->x + 1, p->y);
		free(p);
		p = 0;
	}
	return (ft_clean_stack(err, p, stack, map));
}
