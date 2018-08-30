/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 15:29:13 by xlim              #+#    #+#             */
/*   Updated: 2018/07/18 15:37:02 by xlim             ###   ########.fr       */
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

static t_list	*new_word(const char *src, int n)
{
	char		*out;
	t_list		*ret;

	out = ft_strnew(sizeof(char) * n);
	if (!out)
		return (NULL);
	ft_strncpy(out, src, n);
	ret = ft_lstnew((const void *)out, sizeof(char) * n);
	return (ret);
}

t_list			**ft_strsplitlst(char const *s, char c)
{
	t_list		**out;
	int			i;
	int			j;

	i = -1;
	if (!s || !c)
		return (NULL);
	out = malloc(sizeof(t_list *) * (count_word((char *)s, c) + 1));
	if (!out)
		return (NULL);
	while (s[++i])
	{
		if (s[i] != c)
		{
			j = i;
			while (s[j] && s[j] != c)
				j++;
			ft_lstadd(out, new_word(s + i, j - i));
			i = --j;
		}
	}
	return (out);
}
