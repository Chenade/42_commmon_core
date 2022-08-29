/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:44:37 by ykuo              #+#    #+#             */
/*   Updated: 2022/08/29 18:01:23 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int	main(int argc, char *argv[])
{
	int		i;
	int		fd = 1;
	char	*l;

	i = 1;
	if (argc == 1)
		fd = 0;
	else
		fd = open (argv[i++], O_RDONLY, 0);
	if (fd >= 0)
	{
		printf("File opened successfully!\n");
		while (1){
			l = get_next_line (fd);
			if (!l)
				break ;
			printf("%s", l);
			free (l);
		}
		close (fd);
	}
	// (void) argc;
	return (0);
}
