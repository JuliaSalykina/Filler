/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_power.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:52:31 by mannette          #+#    #+#             */
/*   Updated: 2019/04/30 20:35:06 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_power(unsigned int n, int step)
{
	if (step == 0)
		return (1);
	while (n != 1)
	{
		if (n % step != 0 || n == 0)
		{
			return (0);
		}
		n /= step;
	}
	return (1);
}