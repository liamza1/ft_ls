/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:19:03 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/20 10:11:24 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putstrn_fd(char const *source, size_t max_length
								, int file_descriptor)
{
	size_t		length;

	length = ft_strlen(source);
	if (max_length < length)
		length = max_length;
	write(file_descriptor, source, length);
}
