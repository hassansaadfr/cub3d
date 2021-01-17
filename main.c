/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:07:50 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/17 21:17:16 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/cub3d.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_errors(INVALID_ARGS);
	if (argc > 3)
		ft_errors(TOO_MUCH_ARGS);
	if (argc <= 3)
	{
		ft_check_ext(argv[1]);
		ft_printf("MAP OK !");
	}
	return (0);
}
