/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:53:16 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/22 09:30:56 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_list_sort(t_list **first, int (*compare)(void*, void*))
{
	int		changed;
	t_list	*current;

	changed = 1;
	while (changed)
	{
		changed = 0;
		current = *first;
		while (current->next)
		{
			if (compare(current->content, current->next->content) > 0)
			{
				ft_ptrswp(&current->content, &current->next->content);
				changed = 1;
			}
			current = current->next;
		}
	}
}
