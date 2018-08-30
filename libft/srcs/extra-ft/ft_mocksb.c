/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mocksb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 15:59:54 by xlim              #+#    #+#             */
/*   Updated: 2018/07/18 16:36:34 by xlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_mocksb(char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	ret = ft_strnew(ft_strlen(str));
	ret = ft_strtoupper(str);
	while (ret[i])
	{
		if (!ft_isalpha((int)ret[i]))
			j = 0;
		if (j % 2 == 1)
			ret[i] = ft_tolower((int)ret[i]);
		i++;
		j++;
	}
	return (ret);
}
