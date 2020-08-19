/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 22:45:37 by mannette          #+#    #+#             */
/*   Updated: 2020/06/17 05:27:34 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		ft_piece(t_all *all, char *line, int res, int i)
{
	while (i < all->board.y_p)
	{
		res = get_next_line(all->fd, &line);
		if (res <= 0 || !line || !line[0])
		{
			ft_free_map(all);
			ft_free_char(all->board.map2);
			ft_free_char(all->board.piece);
			return (ft_free_line(line));
		}
		if (line[0] == '.' || line[0] == '*')
		{
			all->board.piece[i] = ft_strdup(line);
			free(line);
		}
		else
		{
			ft_free_map(all);
			ft_free_char(all->board.map2);
			return (ft_free_line(line));
		}
		i++;
	}
	return (1);
}

int		ft_map_copy(char *line)
{
	int		i;
	char	*str;

	i = 0;
	str = line;
	while (str[i] != ' ')
		i++;
	return (i + 1);
}

int		ft_read_map(t_all *all, char *line, int res)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (j < all->board.y_map)
	{
		res = get_next_line(all->fd, &line);
		if (res <= 0 || !line || !line[0])
			return (ft_free_line(line));
		if (line[0] >= '0' && line[0] <= '9')
		{
			if (ft_words_len(line) != 2)
				return (ft_free_line(line));
			i = ft_map_copy(line);
			all->board.map2[j] = ft_strdup(&line[i]);
			j++;
			free(line);
		}
		else
			return (ft_free_line(line));
	}
	return (1);
}

int		ft_map(t_all *all, char *line, int res)
{
	res = get_next_line(all->fd, &line);
	if (res <= 0 || !line || !line[0])
	{
		ft_free_char(all->board.map2);
		ft_free_map(all);
		return (ft_free_line(line));
	}
	free(line);
	ft_read_map(all, line, res);
	return (1);
}

void	ft_initialize(t_all *all)
{
	all->board.x_map = 0;
	all->board.y_map = 0;
	all->board.x_p = 0;
	all->board.y_p = 0;
	all->fd = 0;
	all->my_shape = 'F';
	all->enemy_shape = 'F';
	all->x_coord = 0;
	all->y_coord = 0;
	all->x_start = 0;
	all->y_start = 0;
}
