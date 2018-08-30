/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:16:32 by xlim              #+#    #+#             */
/*   Updated: 2018/07/14 21:46:16 by xlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (*(haystack + i))
	{
		j = 0;
		while (*(needle + j) && *(haystack + i + j) == *(needle + j))
			j++;
		if (*(needle + j) == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
