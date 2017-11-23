/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:01:57 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/20 10:06:55 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putendl_fd(char const *source, int file_descriptor)
{
	ft_putstr_fd(source, file_descriptor);
	ft_putchar_fd('\n', file_descriptor);
}
