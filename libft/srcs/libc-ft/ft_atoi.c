/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:52:11 by xlim              #+#    #+#             */
/*   Updated: 2018/07/17 15:19:05 by xlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	get_num_size(const char *str)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (ft_isspace(*(str + i)) || *(str + i) == '-' || *(str + i) == '+')
		i++;
	while (*(str + i) && *(str + i) >= '0' && *(str + i) <= '9')
	{
		count++;
		i++;
	}
	return (count);
}

int			ft_atoi(const char *str)
{
	int		sign;
	int		i;
	int		output;

	sign = 1;
	i = 0;
	output = 0;
	while (ft_isspace(*(str + i)))
		i++;
	if (*(str + i) == '-')
		sign = -1;
	if (get_num_size(str) > 18 && sign < 0)
		return (0);
	else if (get_num_size(str) > 18 && sign > 0)
		return (-1);
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	while (*(str + i) && *(str + i) >= '0' && *(str + i) <= '9')
	{
		output = (output * 10) + (*(str + i) - '0');
		i++;
	}
	return (output * sign);
}
