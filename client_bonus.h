/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:55:05 by moztop            #+#    #+#             */
/*   Updated: 2024/05/24 20:26:13 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include <signal.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"

# define ARG_ERROR "Argument structure is: ./client [int::PID] [str::MESSAGE]"
# define PID_ERROR "Invalid PID, PID structure must be: [int::PID]"
# define STR_ERROR "Invalid MESSAGE, MESSAGE structure must be: [str::MESSAGE]"
# define KILL_ERROR "An error occured when sending a signal to server..."
# define SGU1_NORESPOND "Server does not respond to bit transactions..."
# define SERVER_ERROR "An error occured while connecting to server with PID:"

typedef struct s_status
{
	int				i;
	char			*str;
	pid_t			pid;
}	t_status;

#endif