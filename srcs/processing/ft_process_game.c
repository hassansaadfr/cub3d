/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:57:44 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/20 23:00:51 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_launch_game(char *path)
{
	char		**map_file;
	t_config	*config;

	ft_check_ext(path);
	map_file = ft_open_and_read(path);
	config = ft_parse_map(map_file);
	free_array_str(map_file);
}
