/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <mannette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 20:47:58 by mannette          #+#    #+#             */
/*   Updated: 2020/06/17 07:33:56 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_spaces(char const *s)
{
	int i;

	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	if (!s)
		return (NULL);
	i = ft_spaces(s);
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j++;
	if (s[j] == '\0')
		return (ft_strnew(0));
	if (!(str = ft_strnew(i - j + 1)))
		return (NULL);
	while (j <= i)
	{
		str[k] = s[j];
		k++;
		j++;
	}
	str[k] = '\0';
	return (str);
}
