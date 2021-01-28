/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:07:50 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/28 01:44:21 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_errors(INVALID_ARGS);
	if (argc > 3)
		ft_errors(TOO_MUCH_ARGS);
	if (argc <= 3)
		ft_launch_game(argv[1]);
	system("leaks Cub3d");
	    void    *mlx;
    void    *mlx_win;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    mlx_loop(mlx);
	return (0);
}
