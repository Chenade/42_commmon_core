/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <ykuo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:52:55 by ykuo              #+#    #+#             */
/*   Updated: 2022/11/23 20:52:56 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_usage(void)
{
	ft_printf(P_RED);
	ft_printf("Error: Usage:");
	ft_printf(P_BLUE);
	ft_printf(" ./philo {number_of_philosophers} {time_to_die}");
	ft_printf(" {time_to_eat} {time_to_sleep}");
	ft_printf("[number_of_times_each_philosopher_must_eat]\n");
	ft_printf(P_X);
	exit(EXIT_FAILURE);
}

int	philo_setup(t_data *d, char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (!is_digits(argv[i]))
			print_usage();
		if (i == 1)
			d->count = ft_atoi(argv[i]);
		else if (i == 2)
			d->nbr_die = ft_atoi(argv[i]);
		else if (i == 3)
			d->nbr_eat = ft_atoi(argv[i]);
		else if (i == 4)
			d->nbr_sleep = ft_atoi(argv[i]);
		else if (i == 5)
			d->nbr_meal = ft_atoi(argv[i]);
	}
	if (i == 5)
		d->nbr_meal = -1;
	return (0);
}
