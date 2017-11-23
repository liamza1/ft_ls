/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:52:32 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/22 09:34:20 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_list_size(t_list *begin_list)
{
	if (begin_list->next == NULL)
		return (1);
	return (1 + ft_list_size(begin_list->next));
}
