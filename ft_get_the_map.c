/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_the_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 21:34:20 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/04 17:47:45 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	ft_put_on_link(int *tab, t_map map, int size)
{
	t_map		new_link;
	int			i;

	i = 0;
	new_link = (t_map)malloc(sizeof(t_line));
	new_link->intline = malloc(sizeof(int) * size);
	new_link->size = size;
	while (i < size)
	{
		new_link->intline[i] = tab[i];
		i++;
	}
	new_link->nxt = map;
	return (new_link);
}

static t_map	ft_rev_map(t_map map)
{
	t_map		new_map;

	new_map = NULL;
	while (map != NULL)
	{
		new_map = ft_put_on_link(map->intline, new_map, map->size);
		map = map->nxt;
	}
	return (new_map);
}

static int		*ft_get_int_line(int fd, int *line, int *size)
{
	char		*str;
	char		**split;
	int			i;

	*size = 0;
	if (get_next_line(fd, &str) <= 0)
		return (0);
	split = ft_strsplit(str, ' ');
	while (split[*size])
		*size = *size + 1;
	line = malloc(sizeof(int) * *size);
	i = 0;
	while (i < *size)
	{
		if (!ft_isnbr(split[i]))
		{
			*size = -1;
			return (0);
		}
		line[i] = ft_atoi(split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	return (line);
}

t_map			ft_get_the_map(int fd, t_map map)
{
	int			*line;
	int			size;

	size = 1;
	while (size > 0)
	{
		line = ft_get_int_line(fd, line, &size);
		if (size > 0)
			map = ft_put_on_link(line, map, size);
		free(line);
	}
	if (size < 0)
		return (NULL);
	return (ft_rev_map(map));
}
