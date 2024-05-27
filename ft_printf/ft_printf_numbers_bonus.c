/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:50:29 by moztop            #+#    #+#             */
/*   Updated: 2024/02/28 22:27:09 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static	int	ft_printf_print_number(t_log *log, int number, int len)
{
	if (number == -2147483648)
	{
		if (ft_putnstr_fd("2147483648", 1, 10) == -1)
			return (-1);
		return (10);
	}
	if (number < 0)
		number *= -1;
	if (number == 0 && log->precision == 0)
		return (0);
	if (ft_printf_putnbr(number) == -1)
		return (-1);
	return (len);
}

static	int	ft_printf_hex(unsigned int n, char *base)
{
	if (n < (unsigned int)ft_strlen_recursive(base))
	{
		if (ft_putnchar_fd(base[n % ft_strlen_recursive(base)], 1, 1) == -1)
			return (-1);
	}
	else
	{
		if (ft_printf_hex(n / ft_strlen_recursive(base), base) == -1)
			return (-1);
		if (ft_putnchar_fd(base[n % ft_strlen_recursive(base)], 1, 1) == -1)
			return (-1);
	}
	return (0);
}

static	int	ft_printf_base(t_log *log, unsigned int number)
{
	if (log->dot && log->precision == 0 && number == 0)
		return (0);
	if (log->type == 'x' || log->type == 'X')
	{
		if (log->type == 'x')
		{
			if (ft_printf_hex(number, HEXALOW) != -1)
				return (ft_printf_number_length_hex(log, number));
		}
		else
		{
			if (ft_printf_hex(number, HEXAUP) != -1)
				return (ft_printf_number_length_hex(log, number));
		}
	}
	else
	{
		if (ft_printf_hex(number, DECIMAL) != -1)
			return (ft_printf_number_length_hex(log, number));
	}
	return (-1);
}

int	ft_printf_number_bonus(t_log *log, int number)
{
	int		count;
	int		len;
	int		temp;

	count = 0;
	temp = 0;
	len = ft_printf_number_length(number);
	if (number < 0 || log->plus || log->space)
		log->width--;
	if (!log->dot || (log->precision < len
			&& !(number == 0 && log->precision == 0)))
		log->precision = len;
	count = ft_printf_number_flags(log, number, len);
	if (count == -1)
		return (-1);
	temp = ft_printf_print_number(log, number, len);
	if (temp == -1)
		return (-1);
	count += temp;
	temp = 0;
	if (log->minus && log->width > log->precision)
		temp = ft_putnchar_fd(' ', 1, log->width - log->precision);
	if (temp == -1)
		return (-1);
	return (count + temp);
}

int	ft_printf_base_bonus(t_log *log, unsigned int number)
{
	int		count;
	int		len;
	int		temp;

	temp = 0;
	count = 0;
	len = ft_printf_number_length_hex(log, number);
	if (log->sharp && log->type != 'u' && number != 0)
		log->width -= 2;
	if (!log->dot || (log->precision < len && number != 0))
		log->precision = len;
	count = ft_printf_hex_flags(log, number, len);
	if (count == -1)
		return (-1);
	temp = ft_printf_base(log, number);
	if (temp == -1)
		return (-1);
	count += temp;
	temp = 0;
	if (log->minus && log->width > log->precision)
		temp = ft_putnchar_fd(' ', 1, log->width - log->precision);
	if (temp == -1)
		return (-1);
	return (count + temp);
}
