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

int	philo_start(t_data *d)
{
	(void) d;
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	d;

	if (argc != 5 && argc != 6)
		print_usage();
	ft_bzero(&d, sizeof(d));
	philo_setup(&d, argv);
	philo_start(&d);
	return (0);
}
