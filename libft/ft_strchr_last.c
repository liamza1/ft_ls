/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 07:03:34 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/22 09:14:41 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strchr_last(const char *haystack, int needle)
{
	char			*end;

	end = ft_strchr(haystack, '\0');
	while (end >= haystack)
	{
		if (*end == needle)
			return ((char*)end);
		end--;
	}
	return (NULL);
}
