/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:38:45 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/22 09:37:49 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static void		destroy_list(t_list *list, void (*free_inside)())
{
		if (list->next != NULL)
					destroy_list(list->next, free_inside);
			if (free_inside)
						free_inside(list->content);
				free(list);
}

void			ft_list_clear(t_list **begin_list, void (*free_inside)())
{
		destroy_list(*begin_list, free_inside);
			*begin_list = NULL;
}

