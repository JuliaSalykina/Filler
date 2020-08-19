/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 16:48:08 by mannette          #+#    #+#             */
/*   Updated: 2020/06/17 03:05:01 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		main(void)
{
	t_all	all;
	int		res;

	res = 1;
	ft_initialize(&all);
	if (!ft_valid_players(&all))
		return (0);
	while (1)
	{
		if (!(ft_read_info(&all)))
			return (0);
		if (!(ft_heat(&all)))
			return (0);
		ft_find_coord(&all);
	}
	return (0);
}
