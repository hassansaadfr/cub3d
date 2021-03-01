/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:38:50 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/03/01 16:20:08 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_errors(char *err)
{
	ft_print_msg(err, ERROR_MSG);
	exit(1);
}

int		ft_print_err(char *msg)
{
	ft_print_msg(msg, ERROR_MSG);
	return (0);
}
