/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_wide.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:03:35 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/20 10:12:38 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlen_wide(const wchar_t *original)
{
	const wchar_t	*end;

	end = original;
	while (*end != L'\0')
		end++;
	return (end - original);
}
