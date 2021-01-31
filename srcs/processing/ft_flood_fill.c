/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 03:55:03 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/30 00:13:55 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_should_be_treated(int x, int y, char **map)
{
	int		height;

	height = get_array_size(map);
	if (x < 0 || y < 0 || y >= height || x >= (int)ft_strlen(map[y]))
	{
		return (-1);
	}
	if (!ft_strchr("012NSEWX", map[y][x]))
		return (-1);
	if (map[y][x] == '1')
		return (0);
	if (map[y][x] == '0' || map[y][x] == '2')
	{
		map[y][x] = 'X';
		return (1);
	}
	return (map[y][x] == '0' || map[y][x] == '2');
}

static int		ft_clean_stack(int err, t_list **stack, char **map)
{
	if (err == -1)
		ft_lstclear(stack, free);
	if (DEBUG)
		ft_read_array_str(map);
	free_array_str(map);
	if (err == -1)
	{
		ft_print_msg("Invalid map", ERROR_MSG);
		return (0);
	}
	return (1);
}

static t_list	*ft_list_pop(t_list **list)
{
	t_list	*cur;
	t_list	*next;

	cur = *list;
	next = *list;
	if (*list == NULL || (*list)->next == NULL)
	{
		*list = NULL;
		return (cur);
	}
	while (next->next != NULL)
	{
		cur = next;
		next = next->next;
	}
	cur->next = NULL;
	return (next);
}

static void		ft_add_to_stack(t_list **stack, int x, int y)
{
	t_coord		*coord;
	t_list		*tmp;

	tmp = 0;
	coord = ft_alloc_coord(x, y);
	tmp = ft_lstnew(coord);
	ft_lstadd_back(stack, tmp);
}

int				ft_flood_fill(t_config **config, char **map)
{
	t_list	*stack;
	t_list	*tmp;
	t_coord	*p;
	int		err;

	map = ft_copy_arr((*config)->map);
	p = ft_alloc_coord((*config)->player_pos->x, (*config)->player_pos->y);
	stack = ft_lstnew(p);
	err = 0;
	while (ft_lstsize(stack) > 0 && err != -1)
	{
		tmp = ft_list_pop(&stack);
		p = tmp->content;
		if ((err = ft_should_be_treated(p->x, p->y - 1, map)))
			ft_add_to_stack(&stack, p->x, p->y - 1);
		if ((err = ft_should_be_treated(p->x, p->y + 1, map)))
			ft_add_to_stack(&stack, p->x, p->y + 1);
		if ((err = ft_should_be_treated(p->x + 1, p->y, map)))
			ft_add_to_stack(&stack, p->x + 1, p->y);
		if ((err = ft_should_be_treated(p->x - 1, p->y, map)))
			ft_add_to_stack(&stack, p->x - 1, p->y);
		ft_lstdelone(tmp, free);
	}
	return (ft_clean_stack(err, &stack, map));
}
