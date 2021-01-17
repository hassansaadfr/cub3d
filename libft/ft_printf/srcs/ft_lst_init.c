/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:20:22 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/13 21:26:25 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lst_prec_delone(t_prec **lst)
{
	if (!*lst)
		return ;
	(*lst)->after_dot = 0;
	(*lst)->align_right = 0;
	(*lst)->size = 0;
	(*lst)->sub = 0;
	(*lst)->type = 0;
	(*lst) = NULL;
	free(*lst);
}

int		ft_lst_new_prec(t_prec **lst)
{
	if (!(*lst = malloc(sizeof(t_prec))))
		return (-1);
	(*lst)->after_dot = -1;
	(*lst)->align_right = -1;
	(*lst)->size = 0;
	(*lst)->sub = -1;
	(*lst)->type = 0;
	return (1);
}
