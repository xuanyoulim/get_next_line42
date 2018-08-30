/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:34:31 by xlim              #+#    #+#             */
/*   Updated: 2018/07/16 16:03:09 by xlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strnstr(const char *str, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*needle)
		return ((char *)str);
	while (*(str + i) && i < n)
	{
		j = 0;
		while (*(needle + j) && *(str + i + j) == *(needle + j) && i + j < n)
		{
			j++;
		}
		if (!needle[j])
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
