/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 20:24:46 by mannette          #+#    #+#             */
/*   Updated: 2019/05/03 17:33:30 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;

	if (*s2 == '\0')
		return ((void*)s1);
	i = ft_strlen(s2);
	while (*s1 && len >= i)
	{
		if (*s1 == *s2)
		{
			if (ft_strncmp(s1, s2, i) == 0)
				return ((void*)s1);
		}
		s1++;
		len--;
	}
	return (NULL);
}
