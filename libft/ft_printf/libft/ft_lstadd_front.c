/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 22:12:39 by hsaadaou          #+#    #+#             */
/*   Updated: 2021/01/17 15:39:57 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *newlst)
{
	if (!*alst)
	{
		*alst = newlst;
		return ;
	}
	if (!newlst)
		return ;
	newlst->next = *alst;
	*alst = newlst;
}
