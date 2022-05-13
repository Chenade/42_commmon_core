/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:44:37 by ykuo              #+#    #+#             */
/*   Updated: 2022/05/13 14:55:40 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*line;
	int			ret;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1023)
		return (NULL);
	line = ft_strjoin(line, buffer[fd]);
	ret = 1;
	while (ret > 0 && !cut_line(line))
	{
		ret = read(fd, buffer[fd], BUFFER_SIZE);
		if (ret < 0)
			return (free(line), NULL);
		buffer[fd][ret] = '\0';
		line = ft_strjoin(line, buffer[fd]);
	}
	clear_buffer (buffer[fd]);
	return (line);
}
