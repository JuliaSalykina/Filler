/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 20:33:07 by mannette          #+#    #+#             */
/*   Updated: 2020/06/17 05:29:19 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		ft_free_line(char *line)
{
	if (line)
		free(line);
	return (0);
}

void	ft_free_map(t_all *all)
{
	int i;

	i = 0;
	while (i < all->board.y_map)
	{
		free(all->board.map[i]);
		i++;
	}
	free(all->board.map);
}

void	ft_free_char(char **arr)
{
	char **mas;

	if (arr && *arr)
	{
		mas = arr;
		while (*mas)
			free(*(mas++));
		free(arr);
		arr = NULL;
	}
	if (arr)
	{
		free(arr);
		arr = NULL;
	}
}

void	print_coordinate(t_all *all)
{
	ft_putnbr(all->y_coord);
	write(1, " ", 1);
	ft_putnbr(all->x_coord);
	write(1, "\n", 1);
	ft_free_map(all);
	ft_free_char(all->board.map2);
	ft_free_char(all->board.piece);
}
