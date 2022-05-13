/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:44:37 by ykuo              #+#    #+#             */
/*   Updated: 2022/05/13 11:54:06 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			ret;
	int			cut;

	line = NULL;
	line = ft_strjoin(line, buffer);
	ret = 1;
	cut = 0;
	while (ret > 0 && !cut)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
			break ;
		buffer[ret] = '\0';
		line = ft_strjoin(line, buffer);
		cut = cut_line(line);
	}
	clear_buffer (buffer);
	return (line);
}
