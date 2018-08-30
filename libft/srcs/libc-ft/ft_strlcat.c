/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 21:56:02 by xlim              #+#    #+#             */
/*   Updated: 2018/07/15 15:36:18 by xlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t		ft_strlcat(char *dst, const char *src, size_t n)
{
	int		dlen;
	int		slen;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	dlen = (int)ft_strlen(dst);
	slen = (int)ft_strlen(src);
	if ((int)n < dlen + 1)
		return (n + slen);
	while (dst[i] != '\0')
		i++;
	while (i + j < n - 1 && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dlen + slen);
}
