/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_add_digit_ularge.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 08:35:52 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/20 08:35:53 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** adds a single digit to a number;  be used in atoi implementations
*/

void				ft_atoi_add_digit_ularge(const char c, uintmax_t *number)
{
	if (*number)
		*number *= 10;
	*number += c - '0';
}
