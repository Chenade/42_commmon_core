/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:44:37 by ykuo              #+#    #+#             */
/*   Updated: 2022/05/11 20:09:58 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char 		*line;
	int			ret;

	line = NULL;
	line = ft_strjoin(line, buffer);
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
			break ;
		line = ft_strjoin (line, buffer);
	}
	
	printf("File opened successfully!\n");
	printf ("%s,\n", line);
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
//		if (fd >= 0)
//		{
			l = get_next_line (fd);
			close (fd);
//		}
//		else
//			printf("File opened failed");
//		if (--argc <= 1)
//			break ;
//	}
	return (0);
}
