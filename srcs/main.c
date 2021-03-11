/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:07:50 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/11 11:29:47 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_errors(INVALID_ARGS);
	if (argc > 3)
		ft_errors(TOO_MUCH_ARGS);
	if (argc <= 3)
	{
		if (argc == 2)
			ft_launch_game(argv[1], argc == 3);
		else if (ft_strncmp(argv[2], "--save", 7) == 0)
			ft_launch_game(argv[1], argc == 3);
		else
			ft_errors(INVALID_ARGS);
	}
	return (0);
}
