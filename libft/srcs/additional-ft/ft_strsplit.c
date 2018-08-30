/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 15:55:29 by xlim              #+#    #+#             */
/*   Updated: 2018/07/16 21:06:16 by xlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	count_word(char *str, char c)
{
	size_t		count;
	int			i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != c && str[i])
				i++;
			i--;
		}
		i++;
	}
	return (count);
}

static char		*new_word(const char *src, int n)
{
	char		*out;

	out = ft_strnew(sizeof(char) * n);
	if (!out)
		return (NULL);
	ft_strncpy(out, src, n);
	return (out);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**out;
	int			i;
	int			j;
	int			k;

	i = -1;
	k = 0;
	if (!s || !c)
		return (NULL);
	out = malloc(sizeof(char *) * (count_word((char *)s, c) + 1));
	if (!out)
		return (NULL);
	while (s[++i])
	{
		if (s[i] != c)
		{
			j = i;
			while (s[j] && s[j] != c)
				j++;
			out[k++] = new_word(s + i, j - i);
			i = --j;
		}
	}
	out[k] = NULL;
	return (out);
}
