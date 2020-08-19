/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:19:48 by mannette          #+#    #+#             */
/*   Updated: 2019/05/17 20:03:10 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *str;

	if (dst == src)
		return (dst);
	str = dst;
	while (n > 0)
	{
		n--;
		str[n] = ((unsigned char*)src)[n];
	}
	return (dst);
}
