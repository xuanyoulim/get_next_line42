/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 19:35:25 by xlim              #+#    #+#             */
/*   Updated: 2018/07/15 22:28:56 by xlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*out;
	int		i;

	i = 0;
	if (f && s)
	{
		out = ft_strnew(ft_strlen(s));
		if (!out)
			return (NULL);
		while (*s)
		{
			out[i] = f(*s);
			i++;
			s++;
		}
		return (out);
	}
	else
		return (NULL);
}
