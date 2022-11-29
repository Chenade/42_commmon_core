#include "philo.h"


long long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(int ms)
{
	long int	time;

	time = timestamp();
	while (timestamp() - time < ms)
		usleep(ms / 10);
}

void	free_data(t_data *d)
{
	int	i;

	i = -1;
	while (++i < d->count)
	{
		pthread_mutex_destroy(&d->philo[i].fork_l);
		pthread_mutex_destroy(d->philo[i].fork_r);
	}
	free(d->philo);
	pthread_mutex_destroy(&d->print);
	pthread_mutex_destroy(&d->m_stop);
	pthread_mutex_destroy(&d->m_eat);
	pthread_mutex_destroy(&d->dead);
}

void	ft_printerr(t_data *d, char *s)
{
	printf(P_RED);
	printf("Error: %s\n", s);
	printf(P_X);
	free_data(d);
	exit(EXIT_FAILURE);
}

void	print(t_philo *philo, char *str)
{
	long int	time;

	pthread_mutex_lock(&(philo->info->print));
	time = timestamp() - philo->info->timestamp;
	if (!philo->info->stop && time >= 0 \
			&& time <= INT_MAX && !is_dead(philo, 0))
		printf("%lld %d %s, (%d)\n", timestamp() - philo->info->timestamp, philo->id, str, philo->m_count);
	pthread_mutex_unlock(&(philo->info->print));
}
