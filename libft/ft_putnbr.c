/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 10:43:43 by vkannema          #+#    #+#             */
/*   Updated: 2016/11/10 12:37:56 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_max_value(void)
{
	char	*str;
	int		i;

	str = "2147483648";
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void		ft_putnbr(int n)
{
	if (n < 0 && n > -2147483648)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_max_value();
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n <= 9 && n >= 0)
	{
		ft_putchar(n + 48);
	}
}
