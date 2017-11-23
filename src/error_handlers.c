/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:42:42 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/23 10:44:03 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_list		*read_directory(DIR *opened)
{
	t_list			*names;
	struct dirent	*just_read;

	if (!opened)
		return (NULL);
	names = NULL;
	while ((just_read = readdir(opened)))
		ft_list_push_front(&names, ft_strdup(just_read->d_name));
	return (names);
}

void				read_through_directory(char *folder_name
		, t_list **directory_list
		, t_list **screw_ups)
{
	DIR				*opened;

	opened = opendir(folder_name);
	ft_list_push_back(directory_list, read_directory(opened));
	if (opened)
		closedir(opened);
	else
		directory_open_failed(folder_name, screw_ups);
}
