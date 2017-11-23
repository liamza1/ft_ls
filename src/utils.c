/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:44:29 by lstreak           #+#    #+#             */
/*   Updated: 2017/11/23 10:51:28 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			ft_strcmp_wrapper(void *first, void *second)
{
	int				bleh;

	bleh = ft_strcmp(((t_entry*)first)->short_name
			, ((t_entry*)second)->short_name);
	return (bleh);
}

static int			compare_time_wrapper(void *first
		, void *second)
{
	int				comparison;

	comparison = compare_last_modified_time(lstat_if_sym((t_entry*)first)
			, lstat_if_sym((t_entry*)second));
	if (comparison == 0)
		return (ft_strcmp_wrapper(first, second));
	else
		return (comparison);
}

void				sort_list_entries(t_list **list, t_options *options)
{
	if (options->sort_time_modified)
		ft_list_sort(list, &compare_time_wrapper);
	else
		ft_list_sort(list, &ft_strcmp_wrapper);
	if (options->reverse_sort)
		ft_list_reverse(list);
}
