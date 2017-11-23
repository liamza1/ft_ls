/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrswp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:54:44 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/20 09:55:49 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_ptrswp(void **first, void **second)
{
	void		*temporary;

	temporary = *second;
	*second = *first;
	*first = temporary;
}
