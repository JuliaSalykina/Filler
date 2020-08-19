/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:01:33 by mannette          #+#    #+#             */
/*   Updated: 2019/12/22 18:59:17 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		znak;
	long	number;

	i = 0;
	number = 0;
	znak = 1;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		znak = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((number * 10) / 10 != number || number * 10 + str[i] - '0' < number)
			return ((znak < 0) ? 0 : -1);
		number = number * 10 + str[i] - '0';
		i++;
	}
	return (znak * number);
}
