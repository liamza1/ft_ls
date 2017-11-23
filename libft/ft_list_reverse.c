/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:51:20 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/22 09:28:49 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_reverse(t_list **begin_list)
{
	t_list		*this_one;
	t_list		*next_one;
	t_list		*last;

	this_one = *begin_list;
	last = NULL;
	while (this_one != NULL)
	{
		next_one = this_one->next;
		this_one->next = last;
		last = this_one;
		this_one = next_one;
	}
	*begin_list = last;
}
