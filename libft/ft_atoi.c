/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:23:41 by vkannema          #+#    #+#             */
/*   Updated: 2016/11/04 11:40:09 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int i;
	int inf;
	int nb_final;

	i = 0;
	nb_final = 0;
	inf = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '-')
	{
		inf = -1;
		i++;
	}
	if (str[i] == '+' && inf != -1)
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		nb_final = nb_final * 10;
		nb_final = nb_final + (str[i] - 48);
		i++;
	}
	return (nb_final * inf);
}
