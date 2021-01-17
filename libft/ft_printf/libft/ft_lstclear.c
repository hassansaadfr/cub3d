/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadaou <hsaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 22:33:23 by hsaadaou          #+#    #+#             */
/*   Updated: 2020/11/21 22:41:25 by hsaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *current;

	current = *lst;
	if (!del)
		return ;
	while (current->next)
	{
		del((*lst)->content);
		current = *lst;
		*lst = current->next;
		free(current);
	}
	*lst = NULL;
}
