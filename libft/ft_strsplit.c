/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:35:26 by mannette          #+#    #+#             */
/*   Updated: 2019/04/28 22:58:17 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_worlen(char const *s, char c)
{
	int	l;

	l = 0;
	while (s[l] && s[l] != c)
		l++;
	return (l);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		j;
	int		i;
	int		k;

	if (!s || !(str = (char**)malloc(sizeof(*str) *
		((j = ft_words(s, c)) + 1))))
		return (NULL);
	k = 0;
	while (k <= j)
	{
		i = 0;
		while (*s == c)
			s++;
		if (!(str[k] = ft_strnew(ft_worlen(s, c))))
		{
			ft_free(str);
			return (NULL);
		}
		while (*s != c && *s)
			str[k][i++] = *s++;
		k++;
	}
	str[k - 1] = 0;
	return (str);
}
