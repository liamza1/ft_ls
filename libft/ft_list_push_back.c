/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:42:31 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/22 09:09:24 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_push_back(t_list **begin_list, void *content)
{
	t_list *new_one;

	new_one = ft_list_create_elem(content);
	if (*begin_list == NULL)
		*begin_list = new_one;
	else
		ft_list_find_end(*begin_list)->next = new_one;
}
