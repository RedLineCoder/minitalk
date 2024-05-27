/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:42:24 by moztop            #+#    #+#             */
/*   Updated: 2024/05/22 18:24:27 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static	int	ft_printf_hex(unsigned int n, char *base)
{
	if (n < (unsigned int)ft_strlen(base))
	{
		if (ft_putnchar_fd(base[n % ft_strlen(base)], 1, 1) == -1)
			return (-1);
	}
	else
	{
		if (ft_printf_hex(n / ft_strlen(base), base) == -1)
			return (-1);
		if (ft_putnchar_fd(base[n % ft_strlen(base)], 1, 1) == -1)
			return (-1);
	}
	return (0);
}

int	ft_printf_number(int number)
{
	int	len;

	len = ft_printf_number_length(number);
	if (number < 0)
		len++;
	if (number == -2147483648)
	{
		if (ft_putnstr_fd("-2147483648", 1, 11) == -1)
			return (-1);
		return (11);
	}
	if (ft_printf_putnbr(number) == -1)
		return (-1);
	return (len);
}

int	ft_printf_base(t_log *log, unsigned int number)
{
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
