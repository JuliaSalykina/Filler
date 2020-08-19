/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 17:34:29 by mannette          #+#    #+#             */
/*   Updated: 2019/04/23 17:41:42 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_len(int num)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		len++;
		if (num == -2147483648)
			return (11);
		num *= -1;
	}
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	len = ft_len(n);
	if (n == 0)
		len++;
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (n == 0)
		str[--len] = 0 + '0';
	if (n < 0)
		str[0] = '-';
	while (n != 0)
	{
		str[--len] = (n < 0) ? -(n % 10) + '0' : n % 10 + '0';
		n /= 10;
	}
	return (str);
}
