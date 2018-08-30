/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 22:32:46 by xlim              #+#    #+#             */
/*   Updated: 2018/07/16 21:02:13 by xlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*out;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	k = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (j == i || j == 0)
		return (ft_strnew(1));
	j--;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	out = ft_strnew(j - i + 1);
	if (!out)
		return (NULL);
	while (i <= j)
	{
		out[k++] = s[i++];
	}
	return (out);
}
