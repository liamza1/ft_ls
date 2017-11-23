/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_large_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:31:12 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/20 10:08:55 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_large_fd(intmax_t number, int file_descriptor)
{
	char	*string;

	string = ft_itoa_large(number);
	ft_putstr_fd(string, file_descriptor);
	free(string);
}
