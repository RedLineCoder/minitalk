/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:35:57 by moztop            #+#    #+#             */
/*   Updated: 2024/05/24 20:28:01 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	signal_handler(int signo, siginfo_t *info, void *context)
{
	static t_status	status;

	(void)context;
	if (info->si_pid != 0)
		status.pid = info->si_pid;
	if (signo == SIGUSR2)
		status.c |= (0b00000001 << status.i);
	status.i++;
	if (status.i == 7)
	{
		ft_printf("%c", status.c);
		status.i = 0;
		status.c = 0;
	}
	if (kill(status.pid, SIGUSR1) == -1)
	{
		ft_printf("%s\n", KILL_ERROR);
		exit(EXIT_FAILURE);
	}
}

void	listen_signal(void)
{
	struct sigaction	sig_action;

	sigemptyset(&sig_action.sa_mask);
	sig_action.sa_sigaction = &signal_handler;
	sig_action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sig_action, NULL) == -1)
	{
		ft_printf("%s\n", SGU1_CHNG_ERROR);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sig_action, NULL) == -1)
	{
		ft_printf("%s\n", SGU2_CHNG_ERROR);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_printf("%s\n", ARG_ERROR);
		exit(EXIT_FAILURE);
	}
	ft_printf("Server PID: %d\n", getpid());
	listen_signal();
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
