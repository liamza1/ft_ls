/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:44:14 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/23 10:49:58 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void				print_arrow_to_symlink(t_entry *entry)
{
	char		buffer[READLINK_BUFSIZE];

	if (entry->is_symlink)
	{
		ft_putstr(" -> ");
		write(1, buffer, readlink(entry->long_name, buffer, READLINK_BUFSIZE));
	}
}

void					print_entry(t_entry *entry, t_options *options
		, t_strlens *strlens)
{
	if (options->long_format)
	{
		print_file_options(entry, strlens);
		ft_putchar(' ');
		ft_putstr(entry->short_name);
		print_arrow_to_symlink(entry);
		ft_putchar('\n');
	}
	else
		ft_putendl(entry->short_name);
}

void					print_total_block_size(t_list *entries)
{
	unsigned long long	total;
	char				*string;

	total = 0;
	while (entries)
	{
		total += lstat_if_sym(((t_entry*)entries->content))->st_blocks;
		entries = entries->next;
	}
	ft_putstr("total ");
	string = ft_itoa_ularge(total);
	ft_putstr(string);
	free(string);
	ft_putchar('\n');
}

int						name_begins_with_dot(char *long_name)
{
	char				*folder;

	folder = ft_strchr(long_name, '\0');
	while (folder > long_name && *(folder - 1) != '/')
		folder--;
	return (*folder == '.');
}

int						should_print_folder(char *long_name
		, t_options *options)
{
	if (options->handling_recursives && !options->show_all)
		return (!name_begins_with_dot(long_name));
	return (1);
}
