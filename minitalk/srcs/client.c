/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:13:49 by ykuo              #+#    #+#             */
/*   Updated: 2022/08/18 18:13:51 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		ft_printf("\033[91mError: \033[93mPID error\033[0m\n");
		return (1);
	}
	return (0);
}

static void	send_char(int pid, int character, size_t *str_len)
{
	int	count;
	int	err;

	count = 0;
	while (count <= 7)
	{
		if ((character >> count) & 1)
			err = kill(pid, SIGUSR1);
		else
			err = kill(pid, SIGUSR2);
		if (err == -1)
		{
			ft_printf("\033[91mError signal\033[0m\n");
			exit(EXIT_FAILURE);
		}
		count += 1;
		while (g_response != 1)
			;
		g_response = 0;
		(*str_len) += 1;
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
		ft_printf("\033[91mError: \033[93mUsages: \033[0m<pid> <message>\n");
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
	ft_printf("\033[32mServer received");
	ft_printf(" %ubit, %ubytes\033[0m\n", str_len, str_len / 8);
	return (0);
}
