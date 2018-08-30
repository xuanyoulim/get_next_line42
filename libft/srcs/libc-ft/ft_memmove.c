/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 14:19:48 by xlim              #+#    #+#             */
/*   Updated: 2018/07/16 16:15:35 by xlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (src < dst)
	{
		len--;
		while ((int)len >= 0)
		{
			((char *)(dst))[len] = ((char *)(src))[len];
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			((char *)(dst))[i] = ((char *)(src))[i];
			i++;
		}
	}
	return (dst);
}
