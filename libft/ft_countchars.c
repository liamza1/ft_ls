/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 08:39:19 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/20 10:36:20 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_countchars(char const *haystack, char needle
										, size_t length)
{
	size_t			count;
	size_t			i;

	count = 0;
	i = 0;
	while (i < length)
	{
		if (haystack[i] == needle)
			count++;
		i++;
	}
	return (count);
}
