/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 14:32:08 by xlim              #+#    #+#             */
/*   Updated: 2018/07/16 15:36:35 by xlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*ptr;

	i = 0;
	ptr = (char *)s;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (ptr);
		ptr++;
		i++;
	}
	return (NULL);
}
