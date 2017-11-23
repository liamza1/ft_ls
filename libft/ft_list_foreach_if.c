/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:57:35 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/20 09:58:34 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_list_foreach_if(t_list *list
								, void (*function)(void *)
								, void *data_ref
								, int (*compare)())
{
	while (list)
	{
		if (compare(list->content, data_ref))
			function(list->content);
		list = list->next;
	}
}
