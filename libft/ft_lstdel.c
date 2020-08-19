/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:58:40 by mannette          #+#    #+#             */
/*   Updated: 2019/05/16 18:01:01 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;

	if (*alst && del)
	{
		while (*alst)
		{
			list = *alst;
			del((*alst)->content, (*alst)->content_size);
			*alst = list->next;
		}
		free(list);
		list = NULL;
	}
}
