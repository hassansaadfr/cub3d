/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 03:55:03 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/24 22:50:44 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_list	*ft_list_pop(t_list **list)
{
	struct s_list	*cur;
	struct s_list	*next;

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

static int		get_array_size(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static int		ft_should_be_treated(int x, int y, char **map)
{
	int	height;

	height = get_array_size(map);
	if (x < 0 || y < 0 || x >= (int)ft_strlen(map[y]) || y >= height)
		return (0);
	return (map[y][x] == '0' || map[y][x] == '2');
}

static void		ft_add_to_stack(t_list **stack, int x, int y)
{
	t_coord		*coord;
	t_list		*tmp;

	tmp = 0;
	coord = malloc(sizeof(t_coord));
	coord->x = x;
	coord->y = y;
	tmp = ft_lstnew(coord);
	ft_lstadd_back(stack, tmp);
	ft_lstclear(&tmp, 0);
}

int				ft_flood_fill(t_coord *player_pos, char **map)
{
	t_list	*stack;
	t_coord	*p;
	int		map_size;
	t_list	*tmp;

	map_size = get_array_size(map);
	stack = ft_lstnew(player_pos);
	while (ft_lstsize(stack) > 0)
	{
		tmp = ft_list_pop(&stack);
		p = tmp->content;
		if (ft_should_be_treated(p->x - 1, p->y, map))
		{
			ft_add_to_stack(&stack, p->x - 1, p->y);
			map[p->y][p->x - 1] = 'X';
		}
		if (ft_should_be_treated(p->x, p->y - 1, map))
		{
			ft_add_to_stack(&stack, p->x, p->y - 1);
			map[p->y - 1][p->x] = 'X';
		}
		if (ft_should_be_treated(p->x, p->y + 1, map))
		{
			ft_add_to_stack(&stack, p->x, p->y + 1);
			map[p->y + 1][p->x] = 'X';
		}
		if (ft_should_be_treated(p->x + 1, p->y, map))
		{
			ft_add_to_stack(&stack, p->x + 1, p->y);
			map[p->y][p->x + 1] = 'X';
		}
		tmp->content = 0;
		p = 0;
		free(tmp);
	}
	ft_lstiter(stack, (void*)ft_free_coord);
	ft_lstclear(&stack, NULL);
	stack = 0;
	ft_read_array_str(map);
	return (1);
}
