/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_justify_left.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 09:11:21 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/22 09:11:57 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putstr_justify_left(char *string
		, size_t total
		, char fill)
{
	size_t			length;
	size_t			i;

	ft_putstr(string);
	length = ft_strlen(string);
	i = 0;
	while (i + length < total)
	{
		ft_putchar(fill);
		i++;
	}
}
