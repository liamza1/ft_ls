/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_literal_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:14:33 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/20 10:37:19 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			print_literal(char c, int fd)
{
	if (c == '\n')
		ft_putstr_fd("\\n", fd);
	else if (c == '\t')
		ft_putstr_fd("\\t", fd);
	else
		ft_putchar_fd(c, fd);
}

void				ft_putstr_literal_fd(char const *source
											, int file_descriptor)
{
	while (*source)
	{
		print_literal(*source, file_descriptor);
		source++;
	}
}
