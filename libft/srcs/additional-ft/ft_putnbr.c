/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 14:18:39 by xlim              #+#    #+#             */
/*   Updated: 2018/07/11 23:28:53 by xlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	int	base;
	int	i;

	base = 1;
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	i = nb;
	while ((i /= 10) > 0)
		base *= 10;
	i = nb;
	while (base)
	{
		ft_putchar((char)((i / base) + 48));
		i %= base;
		base /= 10;
	}
}
