/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permissions_handlers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:47:39 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/23 13:16:04 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		first_executable_permissions(mode_t mode)
{
	if (mode & S_ISUID)
		return ((mode & S_IXUSR) ? 's' : 'S');
	return ((mode & S_IXUSR) ? 'x' : '-');
}

char		second_executable_permissions(mode_t mode)
{
	if (mode & S_ISGID)
		return ((mode & S_IXGRP) ? 's' : 'S');
	return ((mode & S_IXGRP) ? 'x' : '-');
}

char		third_executable_permissions(mode_t mode)
{
	if (mode & S_ISVTX)
		return ((mode & S_IXOTH) ? 't' : 'T');
	return ((mode & S_IXOTH) ? 'x' : '-');
}

char		list_attributes(t_entry *entry)
{
	if ((!entry->is_symlink
				&& listxattr(entry->long_name, NULL, 0, 0) > 0)
			|| (entry->is_symlink
				&& listxattr(entry->long_name, NULL, 0, XATTR_NOFOLLOW) > 0))
		return ('@');
	return (' ');
}

void		print_file_permissions(t_entry *entry)
{
	mode_t	mode;

	mode = lstat_if_sym(entry)->st_mode;
	ft_putchar_if(mode & S_IRUSR, 'r', '-');
	ft_putchar_if(mode & S_IWUSR, 'w', '-');
	ft_putchar(first_executable_permissions(mode));
	ft_putchar_if(mode & S_IRGRP, 'r', '-');
	ft_putchar_if(mode & S_IWGRP, 'w', '-');
	ft_putchar(second_executable_permissions(mode));
	ft_putchar_if(mode & S_IROTH, 'r', '-');
	ft_putchar_if(mode & S_IWOTH, 'w', '-');
	ft_putchar(third_executable_permissions(mode));
	ft_putchar(list_attributes(entry));
}
