/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 19:07:07 by xlim              #+#    #+#             */
/*   Updated: 2018/07/13 13:17:02 by xlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)ft_memalloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	else
		return (str);
}
