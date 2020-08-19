/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 19:09:10 by mannette          #+#    #+#             */
/*   Updated: 2020/06/17 05:36:31 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		ft_words_len(char *line)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

int		ft_valid_piece(t_all *all, char *line, int res)
{
	int		k;
	char	*s;

	res = get_next_line(all->fd, &line);
	if (res <= 0 || !line || !line[0]
	|| ft_strncmp(line, "Piece", 5) != 0 || ft_words_len(line) != 3)
	{
		ft_free_map(all);
		ft_free_char(all->board.map2);
		return (ft_free_line(line));
	}
	s = line;
	while (!(*s >= '0' && *s <= '9'))
		s++;
	all->board.y_p = ft_atoi(s);
	while (*s >= '0' && *s <= '9')
		s++;
	all->board.x_p = ft_atoi(s);
	k = all->board.y_p;
	if (!(all->board.piece = (char**)malloc(sizeof(char*) * (k + 1))))
		return (0);
	ft_memset(all->board.piece, 0, sizeof(char*) * (k + 1));
	free(line);
	return (1);
}

int		ft_valid_map(t_all *all, char *line, int res)
{
	char *s;

	res = get_next_line(all->fd, &line);
	if (res <= 0 || ft_strncmp(line, "Plateau", 7) != 0
	|| ft_words_len(line) != 3 || !line || !line[0])
		return (ft_free_line(line));
	s = line;
	while (!(*s >= '0' && *s <= '9'))
		s++;
	all->board.y_map = ft_atoi(s);
	while (*s >= '0' && *s <= '9')
		s++;
	all->board.x_map = ft_atoi(s);
	free(line);
	ft_create_map(all);
	return (1);
}

int		ft_read_info(t_all *all)
{
	char	*line;
	int		res;

	line = NULL;
	res = 0;
	if (!(ft_valid_map(all, line, res)))
		return (0);
	if (!(ft_map(all, line, res)))
		return (0);
	if (!(ft_valid_piece(all, line, res)))
		return (0);
	if (!(ft_piece(all, line, res, 0)))
		return (0);
	return (1);
}

int		ft_valid_players(t_all *all)
{
	char	*line;
	int		res;

	line = NULL;
	res = 0;
	res = get_next_line(all->fd, &line);
	if (res <= 0 || (ft_strncmp(line, "$$$ exec p", 10) != 0
	&& ft_words_len(line) != 5))
		return (ft_free_line(line));
	if (line[10] == '1' || line[10] == '2')
	{
		all->my_shape = (line[10] == '1' ? 'O' : 'X');
		all->enemy_shape = (line[10] == '1' ? 'X' : 'O');
		free(line);
		return (1);
	}
	else
	{
		free(line);
		return (0);
	}
	free(line);
	return (1);
}
