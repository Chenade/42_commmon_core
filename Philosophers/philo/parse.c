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
	printf(P_RED);
	printf("Error: Usage:");
	printf(P_BLUE);
	printf(" ./philo {number_of_philosophers} {time_to_die}");
	printf(" {time_to_eat} {time_to_sleep}");
	printf("[number_of_times_each_philosopher_must_eat]\n");
	printf(P_X);
	exit(EXIT_FAILURE);
}

int	philo_init(t_data *d)
{
	int	i;

	d->timestamp = timestamp();
	i = -1;
	while (++i < d->count)
	{
		d->philo[i].id = i + 1;
		d->philo[i].last_eat = 0;
		d->philo[i].fork_r = NULL;
		d->philo[i].info = d;
		d->philo[i].m_count = 0;
		pthread_mutex_init(&(d->philo[i].fork_l), NULL);
		if (i == d->count - 1)
			d->philo[i].fork_r = &d->philo[0].fork_l;
		else
			d->philo[i].fork_r = &d->philo[i + 1].fork_l;
		if (pthread_create(&d->philo[i].thread, NULL, \
				&philo_life, &(d->philo[i])) != 0)
			return (-1);
	}
	i = -1;
	while (++i < d->count)
		if (pthread_join(d->philo[i].thread, NULL) != 0)
			return (-1);
	return (0);
}

int	philo_setup(t_data *d, char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
		if (!is_digits(argv[i]))
			print_usage();
	d->philo_eat = 0;
	d->count = ft_atoi(argv[1]);
	d->t_die = ft_atoi(argv[2]);
	d->t_eat = ft_atoi(argv[3]);
	d->t_sleep = ft_atoi(argv[4]);
	if (argv[5])
		d->nbr_meal = ft_atoi(argv[5]);
	if (argv[5] && d->nbr_meal == 0)
		return (1);
	pthread_mutex_init(&d->print, NULL);
	pthread_mutex_init(&d->m_stop, NULL);
	pthread_mutex_init(&d->m_eat, NULL);
	pthread_mutex_init(&d->dead, NULL);
	d->stop = 0;
	d->philo = malloc(sizeof(t_philo) * d->count);
	if (d->philo == NULL)
		ft_printerr(d, "Memory allocated error!");
	philo_init(d);
	return (0);
}
