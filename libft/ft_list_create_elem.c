/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_create_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:35:28 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/20 09:44:27 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_list_create_elem(void *content)
{
	t_list *new_thingy;

	new_thingy = malloc(sizeof(t_list));
	new_thingy->content = content;
	new_thingy->next = NULL;
	return (new_thingy);
}
