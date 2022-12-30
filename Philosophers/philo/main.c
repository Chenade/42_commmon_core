/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <ykuo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:26:58 by ykuo              #+#    #+#             */
/*   Updated: 2022/11/23 20:27:02 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	d;
	int		status;

	if (argc != 5 && argc != 6)
		print_usage();
	ft_bzero(&d, sizeof(d));
	status = philo_setup(&d, argv);
	if (!status)
		free_data(&d);
	return (0);
}
