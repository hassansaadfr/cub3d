/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:07:50 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/17 17:45:10 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/cub3d.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_printf("hello je m'appel %s\n", argv[1]);
	}
	return (0);
}
