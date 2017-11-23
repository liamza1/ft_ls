/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_if.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 09:35:44 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/22 09:36:11 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putchar_if(int boolean, char yes, char no)
{
	if (boolean)
		ft_putchar(yes);
	else
		ft_putchar(no);
}

