/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 19:41:13 by xlim              #+#    #+#             */
/*   Updated: 2018/07/15 22:29:40 by xlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*out;
	unsigned int	i;

	i = 0;
	if (f && s)
	{
		out = ft_strnew(ft_strlen(s));
		if (!out)
			return (NULL);
		while (*s)
		{
			out[i] = f(i, *s);
			i++;
			s++;
		}
		return (out);
	}
	else
		return (NULL);
}
