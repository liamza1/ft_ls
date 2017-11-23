/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharn_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 08:55:24 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/20 08:55:26 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putcharn_fd(char c, size_t number, int file_descriptor)
{
	size_t			i;

	i = 0;
	while (i < number)
	{
		ft_putchar_fd(c, file_descriptor);
		i++;
	}
}
