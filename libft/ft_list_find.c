/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:39:33 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/20 09:40:28 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == NULL)
		return (NULL);
	if (cmp(begin_list->content, data_ref) == 0)
		return (begin_list);
	return (ft_list_find(begin_list->next, data_ref, cmp));
}
