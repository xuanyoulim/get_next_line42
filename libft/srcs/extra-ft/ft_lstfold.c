/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:25:07 by xlim              #+#    #+#             */
/*   Updated: 2018/07/18 15:53:58 by xlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_lstfold(t_list *list, void *(*f)(void *, void *))
{
	void	*ret;

	if (list && f)
	{
		ret = list->content;
		while (list->next)
		{
			list = list->next;
			ret = f(ret, list->content);
		}
		return (ret);
	}
	return (NULL);
}
