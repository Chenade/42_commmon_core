#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define P_Y "\033[33m"
# define P_RED "\033[31m"
# define P_GREEN "\033[92m"
# define P_BLUE "\033[94m"
# define P_X "\033[0m"

typedef struct s_data
{
	int	count;
	int	nbr_die;
	int	nbr_eat;
	int	nbr_sleep;
	int	nbr_meal;
}	t_data;

int 	is_digits(char *s);
int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);

void	print_usage(void);
int		philo_setup(t_data *d, char **argv);

#endif
