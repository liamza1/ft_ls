/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 07:01:18 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/20 07:01:20 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strnlen(const char *string, size_t max)
{
	size_t	len;

	len = 0;
	while (string[len] != '\0' && len < max)
		len++;
	return (len);
}
