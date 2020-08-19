/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 04:04:30 by mannette          #+#    #+#             */
/*   Updated: 2020/06/17 05:23:34 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		ft_mod(int num)
{
	if (num < 0)
		num = -num;
	return (num);
}

int		ft_distance(t_all *all, int i, int j)
{
	int k;
	int l;
	int result;
	int current;

	l = 0;
	result = 0;
	current = 0;
	while (l < all->board.y_map)
	{
		k = 0;
		while (k < all->board.x_map)
		{
			if (all->board.map2[l][k] == all->enemy_shape ||
			all->board.map2[l][k] == all->enemy_shape + 32)
			{
				current = ft_mod(l - j) + ft_mod(k - i);
				if (result == 0 || (result != 0 && result > current))
					result = current;
			}
			k++;
		}
		l++;
	}
	return (result);
}

int		ft_heat(t_all *all)
{
	int i;
	int j;

	j = 0;
	while (j < all->board.y_map)
	{
		i = 0;
		while (i < all->board.x_map)
		{
			if (all->board.map2[j][i] == '.')
				all->board.map[j][i] = ft_distance(all, i, j);
			else if (all->board.map2[j][i] == all->my_shape
			|| all->board.map2[j][i] == all->my_shape + 32)
				all->board.map[j][i] = -1;
			else if (all->board.map2[j][i] == all->enemy_shape
			|| all->board.map2[j][i] == all->enemy_shape + 32)
				all->board.map[j][i] = -2;
			i++;
		}
		j++;
	}
	return (1);
}

int		ft_create_map(t_all *all)
{
	int i;
	int j;
	int k;

	i = all->board.x_map;
	j = all->board.y_map;
	if (!(all->board.map = (int**)malloc(sizeof(int*) * j)))
		return (0);
	k = 0;
	while (k < j)
	{
		all->board.map[k] = (int*)malloc(sizeof(int) * i);
		ft_memset(all->board.map[k], 0, sizeof(int) * i);
		k++;
	}
	if (!(all->board.map2 = (char**)malloc(sizeof(char*) * (j + 1))))
	{
		ft_free_char(all->board.map2);
		return (0);
	}
	ft_memset(all->board.map2, 0, sizeof(char*) * (j + 1));
	return (1);
}
