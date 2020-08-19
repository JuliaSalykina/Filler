/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:15:33 by mannette          #+#    #+#             */
/*   Updated: 2019/04/16 18:18:50 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen(s) + 1;
	while (*s)
	{
		s++;
	}
	while (i != 0)
	{
		if (*(char*)s == (char)c)
			return ((char*)s);
		s--;
		i--;
	}
	return (NULL);
}
