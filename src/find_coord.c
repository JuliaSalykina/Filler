/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 01:56:41 by mannette          #+#    #+#             */
/*   Updated: 2020/06/17 07:34:26 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

int		ft_sum(t_all *all, int i, int j, int cross)
{
	if (all->board.piece[j][i] == '*'
	&& all->board.map[all->y_start + j][all->x_start + i] != -2)
	{
		if (all->board.map[all->y_start + j][all->x_start + i] == -1)
			cross++;
		all->sum += all->board.map[all->y_start + j][all->x_start + i];
	}
	else if (all->board.piece[j][i] == '*'
	&& all->board.map[all->y_start + j][all->x_start + i] == -2)
		return (-1);
	return (cross);
}

int		ft_total_sum(t_all *all)
{
	int i;
	int j;
	int cross;

	j = -1;
	cross = 0;
	while (++j < all->board.y_p)
	{
		i = -1;
		while (++i < all->board.x_p)
		{
			if ((cross = ft_sum(all, i, j, cross)) == -1)
			{
				all->sum = -1;
				return (0);
			}
		}
	}
	if (cross == 1)
		return (1);
	else
	{
		all->sum = -1;
		return (0);
	}
}

void	ft_coord(t_all *all, int i, int j, int k)
{
	if (k == 0)
	{
		all->y_start = j;
		all->x_start = i;
		all->sum = 0;
		ft_total_sum(all);
	}
	if (k == 1)
	{
		all->y_coord = j;
		all->x_coord = i;
	}
}

int		ft_find_coord(t_all *all)
{
	int i;
	int j;
	int min_sum;

	j = 0;
	min_sum = 2000000;
	while (j + all->board.y_p < all->board.y_map)
	{
		i = 0;
		while (i + all->board.x_p < all->board.x_map)
		{
			ft_coord(all, i, j, 0);
			if (all->sum != -1 && all->sum < min_sum)
			{
				ft_coord(all, i, j, 1);
				min_sum = all->sum;
			}
			i++;
		}
		j++;
	}
	print_coordinate(all);
	return (0);
}
