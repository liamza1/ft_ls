/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 08:51:27 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/20 08:51:29 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_digits(int number)
{
	int	count;

	if (number == 0)
		return (1);
	if (number == -2147483648)
		return (10);
	number = ft_abs(number);
	count = 0;
	while (number > 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}
