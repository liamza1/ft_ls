/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs_large.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 08:47:38 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/20 08:48:55 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t			ft_abs_large(intmax_t number)
{
	if (number < 0)
		return (-number);
	return (number);
}
