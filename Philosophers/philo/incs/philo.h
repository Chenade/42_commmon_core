#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

# define P_Y "\033[33m"
# define P_RED "\033[31m"
# define P_GREEN "\033[92m"
# define P_BLUE "\033[94m"
# define P_X "\033[0m"

typedef struct s_philo
{
	int				id;
	int				m_count;
	int				is_eating;
	pthread_t		thread;
	long int		last_eat;
	struct s_data	*info;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	fork_l;
}		t_philo;

typedef struct s_data
{
	int				philo_eat;
	int				count;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nbr_meal;

	int				stop;
	long long		timestamp;
	long long		delay;
	t_philo			*philo;
	pthread_mutex_t	print;
	pthread_mutex_t	m_stop;
	pthread_mutex_t	m_eat;
	pthread_mutex_t	dead;
}	t_data;

int 	is_digits(char *s);
int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);

// utils.c
long long	timestamp(void);
void	ft_usleep(int ms);
void	free_data(t_data *d);
void	ft_printerr(t_data *d, char *s);

void	print_usage(void);
int		philo_setup(t_data *d, char **argv);

int		is_dead(t_philo *philo, int nb);
void	print(t_philo *philo, char *str);
void	*philo_life(void *phi);
#endif
