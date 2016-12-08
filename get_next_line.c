/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:56:06 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/08 18:19:43 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free_join(char *new, char *buff)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(new, buff)))
		return (NULL);
	free(new);
	new = NULL;
	return (tmp);
}

char		*ft_put_line(char *str)
{
	int		i;
	int		len;
	char	*new;

	i = 0;
	len = 0;
	while (str[i])
	{
		i++;
		len++;
	}
	new = malloc(sizeof(char) * len + 1);
	i = 0;
	while (str[i] != '\n' && i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static char	*ft_delete(char *str)
{
	char	*new;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if ((str[i] && !str[i + 1]) || !str[i])
	{
		ft_strdel(&str);
		return (NULL);
	}
	new = ft_strdup(str + i + 1);
	ft_strdel(&str);
	return (new);
}

int			get_next_line(const int fd, char **line)
{
	static t_file	files[1000];
	int				ret;
	char			str[BUFF_SIZE + 1];

	if (fd < 0 || BUFF_SIZE < 0 || !line)
		return (-1);
	if (!files[fd].buf)
		files[fd].buf = ft_strnew(1);
	ret = 2;
	while (!(ft_strchr(files[fd].buf, '\n')))
	{
		ret = read(fd, str, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		str[ret] = '\0';
		files[fd].buf = ft_free_join(files[fd].buf, str);
		if (ret == 0 && *(files[fd].buf) == '\0')
			return (0);
		if (ret == 0)
			break ;
	}
	*line = ft_put_line(files[fd].buf);
	files[fd].buf = ft_delete(files[fd].buf);
	return (1);
}
