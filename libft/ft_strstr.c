/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 20:22:11 by mannette          #+#    #+#             */
/*   Updated: 2019/05/03 17:35:29 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t i;

	if (*s2 == '\0')
		return ((void*)s1);
	i = ft_strlen(s2);
	while (*s1)
	{
		if (*s1 == *s2)
		{
			if (ft_strncmp(s1, s2, i) == 0)
				return ((void*)s1);
		}
		s1++;
	}
	return (NULL);
}
