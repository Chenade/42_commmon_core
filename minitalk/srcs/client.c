#include "minitalk.h"

volatile sig_atomic_t	g_response = 0;

static void	handler(int signo, siginfo_t *siginfo, void *unused)
{
	(void)unused;
	(void)siginfo;
	(void)signo;
	g_response = 1;
}

int	sigaction_setup(struct sigaction *act, siginfo_t *siginfo, char *pid)
{
	act->sa_flags = SA_SIGINFO;
	act->sa_sigaction = &handler;
	sigemptyset(&act->sa_mask);
	sigaction(SIGUSR1, act, NULL);
	siginfo->si_pid = ft_atoi(pid);
	if (siginfo->si_pid == 0 || \
		(kill(siginfo->si_pid, 0) && (errno == EPERM || errno == ESRCH)))
	{
		ft_printf("PID error\n");
		return (1);
	}
	return (0);
}

static void	send_char(int pid, int character, size_t *str_len)
{
	int	counter;
	int	err;

	counter = 0;
	while (counter <= 7)
	{
		if ((character >> counter) & 1)
			err = kill(pid, SIGUSR1);
		else
			err = kill(pid, SIGUSR2);
		if (-1 == err)
		{
			ft_printf("Error signal\n");
			exit(EXIT_FAILURE);
		}
		counter++;
		while (g_response != 1)
			;
		g_response = 0;
		(*str_len)++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	act;
	siginfo_t			siginfo;
	int					i;
	size_t				str_len;

	if (argc != 3)
	{
		ft_printf("2 arguments must be passed: PID and message\n");
		return (0);
	}
	if (sigaction_setup(&act, &siginfo, argv[1]) != 0)
		return (0);
	ft_printf("client PID: %d\n", getpid());
	i = 0;
	str_len = 0;
	while (argv[2][i] != '\0')
		send_char(siginfo.si_pid, argv[2][i++], &str_len);
	send_char(siginfo.si_pid, argv[2][i], &str_len);
	ft_printf("\033[32mServer received %ubit, %ubytes\033[0m\n", str_len, str_len / 8);
	return (0);
}
