/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 13:54:39 by lstreak           #+#    #+#             */
/*   Updated: 2017/07/21 15:08:57 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	read_from_fd(int const fd, char **temp)
{
	char	*buff;
	int		read_bytes;
	char	*nstr;

	buff = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1));
	read_bytes = read(fd, buff, BUFF_SIZE);
	if (read_bytes > 0)
	{
		buff[read_bytes] = '\0';
		nstr = ft_strjoin(*temp, buff);
		if (!nstr)
			return (-1);
		free(buff);
		free(*temp);
		*temp = nstr;
	}
	return (read_bytes);
}

static int	clear_temp(char **s1, char **s2)
{
	*s1 = ft_strdup(*s1 + 1);
	free(*s2);
	*s2 = *s1;
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static char	*temp;
	char		*endl_index;
	int			ret;

	if ((!temp && (temp = (char *)ft_memalloc(sizeof(char))) == NULL))
		return (-1);
	endl_index = ft_strchr(temp, ENDL);
	while (endl_index == NULL)
	{
		ret = read_from_fd(fd, &temp);
		if (ret == 0)
		{
			if ((endl_index = ft_strchr(temp, '\0')) == temp)
				return (0);
		}
		else if (ret < 0)
			return (-1);
		else
			endl_index = ft_strchr(temp, ENDL);
	}
	*line = ft_strsub(temp, 0, endl_index - temp);
	if (!*line)
		return (-1);
	return (clear_temp(&endl_index, &temp));
	free(endl_index);
}
