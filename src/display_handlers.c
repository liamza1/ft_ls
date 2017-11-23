/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:42:28 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/23 10:35:48 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			replace_if_greater(uintmax_t *replace_if
		, uintmax_t new_value)
{
	if (*replace_if < new_value)
		*replace_if = new_value;
}

static void			replace_if_greater_int(int *replace_if
		, int new_value)
{
	if (*replace_if < new_value)
		*replace_if = new_value;
}

static void			replace_username_group(t_strlens *strlens, t_entry *entry)
{
	struct passwd	*passwd;
	struct group	*group;

	passwd = getpwuid(lstat_if_sym(entry)->st_uid);
	if (passwd)
		entry->username = ft_strdup(passwd->pw_name);
	else
		entry->username = ft_itoa(lstat_if_sym(entry)->st_uid);
	replace_if_greater(&strlens->username, ft_strlen(entry->username));
	group = getgrgid(lstat_if_sym(entry)->st_gid);
	if (group)
		entry->group_name = ft_strdup(group->gr_name);
	else
		entry->group_name = ft_itoa(lstat_if_sym(entry)->st_gid);
	replace_if_greater(&strlens->group_name, ft_strlen(entry->group_name));
}

static int			get_size_string_length(t_entry *entry
		, uintmax_t *largest_major)
{
	uintmax_t		major;
	uintmax_t		minor;
	int				total;

	entry->file_type_char = get_file_type_char(entry);
	if (entry->file_type_char == 'b' || entry->file_type_char == 'c')
	{
		major = major(entry->stat->st_rdev);
		minor = minor(entry->stat->st_rdev);
		replace_if_greater(largest_major, major);
		entry->first_file_size_string = ft_itoa_ularge(major);
		entry->second_file_size_string = ft_itoa_ularge(minor);
		total = ft_strlen(entry->first_file_size_string)
			+ ft_strlen(entry->second_file_size_string) + 2;
		return (total);
	}
	else
	{
		entry->second_file_size_string =
			ft_itoa_ularge(lstat_if_sym(entry)->st_size);
		return (ft_strlen(entry->second_file_size_string));
	}
}

void				prepare_file_options(t_strlens *strlens
		, t_list *entries
		, t_options *options)
{
	t_entry			*entry;
	uintmax_t		largest_nlink;
	uintmax_t		largest_major;

	ft_bzero(strlens, sizeof(t_strlens));
	largest_nlink = 0;
	largest_major = 0;
	while (entries && (entry = (t_entry*)entries->content))
	{
		if (!should_print_entry(entry, options))
		{
			entries = entries->next;
			continue ;
		}
		replace_if_greater(&largest_nlink, lstat_if_sym(entry)->st_nlink);
		replace_if_greater_int(&strlens->file_size
				, get_size_string_length(entry, &largest_major));
		replace_username_group(strlens, entry);
		entries = entries->next;
	}
	strlens->nlink = ft_count_digits_ularge(largest_nlink);
	if (largest_major)
		strlens->major = ft_count_digits_ularge(largest_major);
}
