/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 03:48:12 by moztop            #+#    #+#             */
/*   Updated: 2024/02/28 22:17:51 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static	char	*ft_base_indicator(t_log *log)
{
	if (log->type == 'x')
		return ("0x");
	else
		return ("0X");
}

static	char	ft_number_sign(t_log *log, int number)
{
	if (log->plus && number >= 0)
		return ('+');
	return ('-');
}

static	int	ft_printf_hex_zero(t_log *log, int len)
{
	int	count;
	int	temp;

	count = 0;
	temp = 0;
	if (!log->minus && log->width > log->precision && log->zero && !log->dot)
		temp = ft_putnchar_fd('0', 1, log->width - log->precision);
	if (temp == -1)
		return (-1);
	count += temp;
	temp = 0;
	if (log->precision > len)
		temp = ft_putnchar_fd('0', 1, log->precision - len);
	if (temp == -1)
		return (-1);
	return (count + temp);
}

int	ft_printf_number_flags(t_log *log, int number, int len)
{
	int	count;
	int	temp;

	count = 0;
	temp = 0;
	if (!log->minus && log->width > log->precision && (!log->zero || log->dot))
		count = ft_putnchar_fd(' ', 1, log->width - log->precision);
	if (count == -1)
		return (-1);
	if (number < 0 || log->plus)
		temp = ft_putnchar_fd(ft_number_sign(log, number), 1, 1);
	else if (log->space)
		temp = ft_putnchar_fd(' ', 1, 1);
	if (temp == -1)
		return (-1);
	count += temp;
	temp = 0;
	if (log->precision > len)
		temp = ft_putnchar_fd('0', 1, log->precision - len);
	else if (!log->minus && log->width > log->precision
		&& log->zero && !log->dot)
		temp = ft_putnchar_fd('0', 1, log->width - log->precision);
	if (temp == -1)
		return (-1);
	return (count + temp);
}

int	ft_printf_hex_flags(t_log *log, unsigned int number, int len)
{
	int	count;
	int	temp;

	temp = 0;
	count = 0;
	if (!log->minus && log->width > log->precision && (!log->zero || log->dot))
		count = ft_putnchar_fd(' ', 1, log->width - log->precision);
	if (count == -1)
		return (-1);
	if (log->sharp && log->type != 'u' && number != 0)
		temp = ft_putnstr_fd(ft_base_indicator(log), 1, 2);
	if (temp == -1)
		return (-1);
	count += temp;
	temp = 0;
	temp = ft_printf_hex_zero(log, len);
	if (temp == -1)
		return (-1);
	return (count + temp);
}
