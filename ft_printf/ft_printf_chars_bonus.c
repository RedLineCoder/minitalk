/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:50:13 by moztop            #+#    #+#             */
/*   Updated: 2024/02/28 22:19:40 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf_char_bonus(t_log *log, char chr)
{
	int	count;
	int	temp;

	count = 0;
	log->precision = 1;
	temp = ft_printf_zero_space_flags(log);
	if (temp == -1)
		return (-1);
	count += temp;
	temp = 0;
	temp = ft_putnchar_fd(chr, 1, log->precision);
	if (temp == -1)
		return (-1);
	count += temp;
	temp = 0;
	if (log->minus && log->width > log->precision)
		temp = ft_putnchar_fd(' ', 1, log->width - log->precision);
	if (temp == -1)
		return (-1);
	count += temp;
	return (count);
}

int	ft_printf_chars_bonus(t_log *log, char *str)
{
	int		count;
	int		temp;

	count = 0;
	if (str == NULL && (!log->dot || log->precision > 6))
		log->precision = 6;
	if (str != NULL && (!log->dot || log->precision > ft_strlen_recursive(str)))
		log->precision = ft_strlen_recursive(str);
	temp = ft_printf_zero_space_flags(log);
	if (temp == -1)
		return (-1);
	count += temp;
	temp = 0;
	temp = ft_printf_chars_print(log, str);
	if (temp == -1)
		return (-1);
	count += temp;
	temp = 0;
	if (log->minus && log->width > log->precision)
		temp = ft_putnchar_fd(' ', 1, log->width - log->precision);
	if (temp == -1)
		return (-1);
	count += temp;
	return (count);
}
