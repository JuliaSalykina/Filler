/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 19:23:50 by mannette          #+#    #+#             */
/*   Updated: 2019/04/21 19:26:26 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int delete;

	delete = 1;
	if (n != 0)
	{
		delete = 1000000000;
		while ((n / delete) == 0)
		{
			delete /= 10;
		}
	}
	if (n < 0)
		ft_putchar_fd('-', fd);
	while (delete > 0)
	{
		ft_putchar_fd((n < 0) ? -(n / delete) + '0' : n / delete + '0', fd);
		n %= delete;
		delete /= 10;
	}
}
