/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:57:53 by xlim              #+#    #+#             */
/*   Updated: 2018/07/16 13:55:34 by xlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && del)
	{
		if ((*alst)->next)
			ft_lstdel(&(*alst)->next, del);
		ft_lstdelone(alst, del);
	}
}
