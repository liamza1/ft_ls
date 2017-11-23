/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:56:04 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/17 13:56:39 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_pathjoin(char *p1, char *p2)
{
	if (!ft_strendswith(p1, "/"))
		return (ft_strjoin(ft_strjoinch(p1, '/'), p2));
	return (ft_strjoin(p1, p2));
}

