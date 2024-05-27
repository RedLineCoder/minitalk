/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointers_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:50:44 by moztop            #+#    #+#             */
/*   Updated: 2024/02/28 22:29:33 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static	int	ft_printf_address(unsigned long n, char *base, int count)
{
	if (n < (unsigned long)ft_strlen_recursive(base))
	{
		if (ft_putnchar_fd(base[n % ft_strlen_recursive(base)], 1, 1) == -1)
			return (-1);
	}
	else
	{
		if (ft_printf_address(n / ft_strlen_recursive(base), base, count) == -1)
			return (-1);
		if (ft_putnchar_fd(base[n % ft_strlen_recursive(base)], 1, 1) == -1)
			return (-1);
	}
	return (count);
}

static	int	ft_printf_pointers(unsigned long address)
{
	int		count;

	count = 0;
	if (ft_putnstr_fd("0x", 1, 2) == -1)
		return (-1);
	count = ft_printf_address(address, HEXALOW,
			ft_printf_number_length_address(address));
	if (count == -1)
		return (-1);
	return (count + 2);
}

int	ft_printf_pointers_bonus(t_log *log, unsigned long address)
{
	int	count;
	int	temp;

	count = 0;
	log->width -= 2;
	if (log->precision < ft_printf_number_length_address(address))
		log->precision = ft_printf_number_length_address(address);
	count = ft_printf_zero_space_flags(log);
	if (count == -1)
		return (-1);
	temp = ft_printf_pointers(address);
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
