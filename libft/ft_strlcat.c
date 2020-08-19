/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:47:27 by mannette          #+#    #+#             */
/*   Updated: 2019/04/22 16:48:45 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t i;
	size_t j;
	size_t all;

	i = ft_strlen(dst);
	j = 0;
	all = ft_strlen(src);
	if (i >= len)
		return (all + len);
	while (src[j] && i < len - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	i -= j;
	return (i + all);
}
