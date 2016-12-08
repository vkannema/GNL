/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:23:40 by vkannema          #+#    #+#             */
/*   Updated: 2016/12/08 18:03:22 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "./libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# define BUFF_SIZE 32

typedef struct	s_file
{
	int		fd;
	char	*buf;
}				t_file;
int				get_next_line(const int fd, char **line);

#endif
