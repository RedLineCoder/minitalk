/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:19:59 by moztop            #+#    #+#             */
/*   Updated: 2024/05/24 20:26:49 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_status	g_status;

void	arg_error_check(int argc, char **argv)
{
	int	index;

	index = -1;
	if (argc != 3)
	{
		ft_printf("%s\n", ARG_ERROR);
		exit(EXIT_FAILURE);
	}
	while (argv[1][++index])
	{
		if (argv[1][index] > '9' || argv[1][index] < '0')
		{
			ft_printf("%s\n", PID_ERROR);
			exit(EXIT_FAILURE);
		}
	}
	if (!argv[2][0])
	{
		ft_printf("%s\n", STR_ERROR);
		exit(EXIT_FAILURE);
	}
}

void	signal_handler(int signo, siginfo_t *info, void *context)
{
	unsigned char	bit;

	(void)signo;
	(void)info;
	(void)context;
	if (g_status.i < 0)
	{
		g_status.i = 6;
		g_status.str++;
		if (*(g_status.str) == 0)
			exit(EXIT_SUCCESS);
	}
	bit = (((*(g_status.str) << g_status.i) & 0b01000000) == 0b01000000);
	g_status.i--;
	if (kill(g_status.pid, bit + SIGUSR1) == -1)
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
		ft_printf("%s\n", SGU1_NORESPOND);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	arg_error_check(argc, argv);
	server_pid = ft_atoi(argv[1]);
	if (kill(server_pid, 0) == -1)
	{
		ft_printf("%s%d\n", SERVER_ERROR, server_pid);
		exit(EXIT_FAILURE);
	}
	g_status.i = 6;
	g_status.str = argv[2];
	g_status.pid = server_pid;
	listen_signal();
	signal_handler(0, NULL, NULL);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
