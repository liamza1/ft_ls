/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:45:35 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/20 09:47:32 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_push_front(t_list **begin_list, void *content)
{
	t_list *new_one;

	new_one = ft_list_create_elem(content);
	new_one->next = *begin_list;
	*begin_list = new_one;
}
