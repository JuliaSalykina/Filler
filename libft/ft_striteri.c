/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:42:28 by mannette          #+#    #+#             */
/*   Updated: 2019/04/21 15:48:16 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t i;
	size_t j;

	if (!s || !f)
		return ;
	i = 0;
	j = ft_strlen(s);
	while (i < j)
	{
		f(i, s + i);
		i++;
	}
}
