/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:26:43 by xlim              #+#    #+#             */
/*   Updated: 2018/07/14 16:07:06 by xlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	void	*ptr;

	i = 0;
	ptr = NULL;
	while (i < n)
	{
		((char *)dst)[i] = ((const char *)src)[i];
		if (((unsigned char *)src)[i] == (unsigned char)c)
		{
			ptr = &dst[i + 1];
			return (ptr);
		}
		i++;
	}
	return (ptr);
}
