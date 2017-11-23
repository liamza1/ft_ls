/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handlers_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:43:20 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/23 10:31:24 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_folder_name_before(char *folder_name
		, t_options *options)
{
	if (options->printed_folder_already)
		ft_putstr("\n");
	ft_putstr(folder_name);
	ft_putstr(":\n");
	options->printed_folder_already = 1;
}

void			handle_directories(t_list *folder_name
		, t_list *directory
		, t_options *options)
{
	char		*string;
	t_bool		print_folder;

	while (folder_name)
	{
		string = (char*)folder_name->content;
		print_folder = should_print_folder(string, options);
		if (options->print_folder_names_before && print_folder)
			print_folder_name_before(string, options);
		if (directory->content)
			handle_directory(string, (t_list*)directory->content, print_folder
					, options);
		folder_name = folder_name->next;
		directory = directory->next;
	}
}

t_bool			should_print_entry(t_entry *entry, t_options *options)
{
	t_bool		bleh;

	bleh = *entry->short_name != '.'
		|| options->show_all
		|| options->handling_screwups;
	return (bleh);
}

char			*get_readlink_string(char *link_path)
{
	char		buffer[READLINK_BUFSIZE];
	size_t		lu;

	lu = readlink(link_path, buffer, READLINK_BUFSIZE);
	if (lu >= READLINK_BUFSIZE)
		ft_putendl_exit("Link filename too long\n", 1);
	buffer[lu] = '\0';
	return (ft_strdup(buffer));
}

t_stat			*lstat_if_sym(t_entry *entry)
{
	if (entry->is_symlink)
		return (entry->lstat);
	else
		return (entry->stat);
}
