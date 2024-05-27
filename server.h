/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:31:09 by moztop            #+#    #+#             */
/*   Updated: 2024/05/24 17:22:05 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

# define ARG_ERROR "Too many arguments! Server does not take parameters..."
# define SGU1_CHNG_ERROR "A problem occurred when changing SIGUSR1's behavior"
# define SGU2_CHNG_ERROR "A problem occurred when changing SIGUSR2's behavior"
# define KILL_ERROR "An error occured when sending a signal to client..."

typedef struct s_status
{
	unsigned char	c;
	int				i;
	pid_t			pid;
}	t_status;

#endif