/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:06:51 by mannette          #+#    #+#             */
/*   Updated: 2019/04/17 18:06:53 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*str;
	const unsigned char	*str1;

	if (dst == src)
		return (dst);
	str = dst;
	str1 = src;
	if (str1 < str)
		ft_memcpy(str, str1, len);
	if (str1 > str)
	{
		while (len > 0)
		{
			*str = *str1;
			str++;
			str1++;
			len--;
		}
	}
	return (dst);
}
