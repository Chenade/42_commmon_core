/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:44:37 by ykuo              #+#    #+#             */
/*   Updated: 2022/05/13 11:46:52 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	cut_line(char *line)
{
	int	i;

	i = -1;
	while (line && line[++i])
	{
		if (line[i] == 10)
			return (i + 1);
	}
	return (0);
}

void	clear_buffer(char *buffer)
{
	int	i;
	int	pos;

	i = 0;
	pos = cut_line(buffer); 
	while (buffer[pos + i] && pos)
	{
		buffer[i] = buffer[pos +  i];
		i += 1;
	}
	buffer[i] = '\0';
}

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char 		*line;
	int			ret;
	int			cut;

	line = NULL;
	line = ft_strjoin_vi(line, buffer);
	ret = 1;
	cut = 0;
	while (ret > 0 && !cut)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
			break ;
		buffer[ret] = '\0';
		line = ft_strjoin_vi (line, buffer);
		cut = cut_line(line);
	}
	clear_buffer (buffer);
	return (line);
}

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int	main(int argc, char *argv[])
{
	int		i;
	int		fd;
	char	*l;

	i = 1;
	//while (1)
//	{
//		if (argc == 1)
//			fd = 0;
//		else
			fd = open (argv[i++], O_RDONLY, 0);
		if (fd >= 0)
		{
			printf("File opened successfully!\n");
			l = get_next_line (fd);
			printf("%s", l);
			l = get_next_line (fd);
			printf("%s", l);
			l = get_next_line (fd);
			printf("%s", l);
			l = get_next_line (fd);
			printf("%s", l);
			close (fd);
		}
		else
			printf("File opened failed");
//		if (--argc <= 1)
//			break ;
//	}
	(void) argc;
	return (0);
}
