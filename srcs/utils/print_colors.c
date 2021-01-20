/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:59:45 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/20 20:21:32 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_print_success(void)
{
	ft_printf("\033[1;32m");
}

static void	ft_print_warning(void)
{
	ft_printf("\033[1;33m");
}

static void	ft_print_error(void)
{
	ft_printf("\033[1;31m");
}

static void	ft_reset_print(void)
{
	ft_printf("\033[0m");
}

void		ft_print_msg(char *str, int color)
{
	if (color == STANDARD_MSG)
	{
		ft_reset_print();
		ft_printf("%s\n", str);
	}
	if (color == SUCCESS_MSG)
	{
		ft_print_success();
		ft_printf("%s\n", str);
	}
	if (color == WARNING_MSG)
	{
		ft_print_warning();
		ft_printf("%s\n", str);
	}
	if (color == ERROR_MSG)
	{
		ft_print_error();
		ft_printf("Error.\n%s\n", str);
	}
	if (color == CLEAR_CONSOLE)
	{
		ft_printf("\e[1;1H\e[2J");
	}
	ft_reset_print();
}
