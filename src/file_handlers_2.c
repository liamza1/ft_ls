/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handlers_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:43:13 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/23 10:40:47 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char			*get_folder_name(char *file, char *short_name)
{
	size_t			length;

	if (file == short_name)
		return (ft_strdup("."));
	length = short_name - 1 - file;
	if (!length)
		length++;
	return (ft_strsub(file, 0, length));
}

static int			is_a_real_file(char *file)
{
	DIR				*directory;
	struct dirent	*entry;
	char			*folder_name;
	char			*short_name;

	short_name = ft_strchr_last(file, '/');
	if (short_name)
		short_name++;
	else
		short_name = file;
	folder_name = get_folder_name(file, short_name);
	directory = opendir(folder_name);
	while ((entry = readdir(directory)))
	{
		if (ft_strequ(short_name, entry->d_name))
		{
			free(folder_name);
			closedir(directory);
			return (1);
		}
	}
	free(folder_name);
	closedir(directory);
	return (0);
}

static char			*long_to_short_name(char *long_name)
{
	char			*start;

	if (ft_strequ(long_name, "/"))
		return (long_name);
	start = ft_strchr(long_name, '\0');
	while (start > long_name && *(start - 1) != '/')
		start--;
	return (start);
}

void				directory_open_failed(char *failing_name
, t_list **screw_ups)
{
	if (errno == ENOTDIR && is_a_real_file(failing_name))
		ft_list_push_front(screw_ups, failing_name);
	else
	{
		if (errno == ENOENT || errno == ENOTDIR)
		{
			ft_putstr_fd("ft_ls: ", 2);
			ft_putstr_fd(failing_name, 2);
			ft_putendl_fd(": No such file or directory", 2);
		}
		else
		{
			ft_putstr_fd("ft_ls: ", 2);
			perror(long_to_short_name(failing_name));
		}
	}
}

char				get_file_type_char(t_entry *entry)
{
	if (entry->is_symlink)
		return ('l');
	if (S_ISBLK(entry->stat->st_mode))
		return ('b');
	else if (entry->stat->st_mode & S_IFCHR)
		return ('c');
	else if (S_ISSOCK(entry->stat->st_mode))
		return ('s');
	else if (entry->stat->st_mode & S_IFIFO)
		return ('p');
	else if (entry->stat->st_mode & S_IFDIR)
		return ('d');
	return ('-');
}
