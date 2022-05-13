/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:44:37 by ykuo              #+#    #+#             */
/*   Updated: 2022/05/13 11:51:49 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
