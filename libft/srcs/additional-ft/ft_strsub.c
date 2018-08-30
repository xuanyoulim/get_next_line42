/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 21:22:12 by xlim              #+#    #+#             */
/*   Updated: 2018/08/28 21:06:05 by xlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*output;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	output = ft_memalloc(sizeof(char) * (len + 1));
	if (!output)
		return (NULL);
	while (i < len)
	{
		output[i] = s[start];
		i++;
		start++;
	}
	output[i] = '\0';
	return (output);
}
