/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 17:05:17 by vkannema          #+#    #+#             */
/*   Updated: 2016/11/11 11:50:32 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
	{
		i++;
	}
	if (str1[i] != str2[i] && (str1[i] != '\0' || str2[i] != '\0'))
	{
		return (str1[i] - str2[i]);
	}
	return (0);
}
