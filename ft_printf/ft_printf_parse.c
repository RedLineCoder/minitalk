/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:45:03 by moztop            #+#    #+#             */
/*   Updated: 2024/05/22 18:24:35 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static	void	ft_printf_log_init(t_log *log)
{
	log->type = 0;
}

int	ft_printf_parse(char *start, va_list *args)
{
	t_log	log;

	ft_printf_log_init(&log);
	while (!ft_strchr(TYPE, *start) && *start)
		start++;
	log.type = *start;
	return (ft_printf_print_type(&log, args));
}
