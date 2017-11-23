/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_justify_right.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:21:59 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/20 09:24:42 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putnbr_justify_right(int number
											, size_t total
											, char fill)
{
	char			*string;

	string = ft_itoa(number);
	ft_putstr_justify_right(string, total, fill);
	free(string);
}
