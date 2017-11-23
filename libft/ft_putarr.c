/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:33:12 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/20 09:33:14 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putarr(void const **source, size_t length, t_printer printer)
{
	size_t		i;

	i = 0;
	while (i < length)
	{
		ft_putchar('[');
		ft_putnbr(i);
		ft_putstr("::");
		printer(source[i]);
		ft_putchar(']');
		i++;
	}
}
