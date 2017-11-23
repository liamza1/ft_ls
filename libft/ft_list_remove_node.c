/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:50:10 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/22 09:27:13 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** removes the t_list node from the list original
** NOTE: need to do free(old_one) in line 34 (insert)
*/

#include "libft.h"

void					ft_list_remove_node(t_list **original
											, t_list *to_remove
											, void (*free_inside)(void*))
{
	t_list				*old_one;

	if (original && *original && to_remove)
	{
		if (*original == to_remove)
		{
			old_one = *original;
			*original = (*original)->next;
			if (free_inside)
				free_inside(old_one->content);
		}
		else
			ft_list_remove_node(&((*original)->next), to_remove, free_inside);
	}
}
