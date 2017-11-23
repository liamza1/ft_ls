/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 08:38:33 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/20 08:38:35 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Frees the thing created by ft_strsplit
*/

void			ft_strsplit_free(char **thing)
{
	size_t		i;

	i = 0;
	while (thing[i])
	{
		free(thing[i]);
		i++;
	}
	free(thing);
}
