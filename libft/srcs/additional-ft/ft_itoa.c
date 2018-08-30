/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 19:02:06 by xlim              #+#    #+#             */
/*   Updated: 2018/07/17 15:12:27 by xlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_itoa(int n)
{
	int		int_count;
	char	*str;

	int_count = ft_intdigit(n);
	str = ft_strnew(int_count);
	if (!str)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (int_count >= 0)
	{
		int_count--;
		str[int_count] = (n % 10) + '0';
		n /= 10;
		if (n == 0)
			int_count--;
	}
	return (str);
}
