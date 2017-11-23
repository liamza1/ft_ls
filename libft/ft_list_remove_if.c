/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:48:52 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/22 09:20:55 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note: does not free the stuff inside the linked lists
*/

void			ft_list_remove_if(t_list **begin_list
									, void *data_ref
									, int (*cmp)())
{
	t_list		*free_me;

	if (*begin_list)
	{
		if (cmp((*begin_list)->content, data_ref))
		{
			free_me = *begin_list;
			*begin_list = (*begin_list)->next;
			free(free_me);
			ft_list_remove_if(begin_list, data_ref, cmp);
		}
		else
			ft_list_remove_if(&(*begin_list)->next, data_ref, cmp);
	}
}
