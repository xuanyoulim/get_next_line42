/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 14:08:32 by xlim              #+#    #+#             */
/*   Updated: 2018/07/16 14:44:47 by xlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*out;
	t_list	*new;

	if (!lst && !f)
		return (NULL);
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new = f(lst);
	out = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new->next = f(lst)))
		{
			free(new->next);
			new->next = NULL;
			return (out);
		}
		new = new->next;
		lst = lst->next;
	}
	return (out);
}
