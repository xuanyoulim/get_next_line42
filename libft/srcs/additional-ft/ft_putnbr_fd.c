/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 23:12:31 by xlim              #+#    #+#             */
/*   Updated: 2018/07/11 23:13:39 by xlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_fd(int nb, int fd)
{
	int base;
	int i;

	base = 1;
	if (nb == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	i = nb;
	while ((i /= 10) > 0)
		base *= 10;
	i = nb;
	while (base)
	{
		ft_putchar_fd((char)((i / base) + 48), fd);
		i %= base;
		base /= 10;
	}
}
