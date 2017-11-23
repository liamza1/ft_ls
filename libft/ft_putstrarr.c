/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:32:16 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/20 09:32:18 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putstrarr(char const **source, size_t length)
{
	size_t		i;

	i = 0;
	while (i < length)
	{
		ft_putchar('[');
		ft_putnbr(i);
		ft_putstr("::");
		ft_putstr(source[i]);
		ft_putchar(']');
		i++;
	}
}
