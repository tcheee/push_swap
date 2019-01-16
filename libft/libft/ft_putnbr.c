/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:50:23 by ayguillo          #+#    #+#             */
/*   Updated: 2018/11/12 17:29:21 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		n = 8;
		ft_putstr("-214748364");
	}
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * -1);
	}
	if (n < 10 && n >= 0)
		ft_putchar('0' + n);
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar('0' + (n % 10));
	}
}