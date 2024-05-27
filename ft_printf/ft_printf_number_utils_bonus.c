/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number_utils_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:20:39 by moztop            #+#    #+#             */
/*   Updated: 2024/02/28 22:22:06 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf_putnbr(int n)
{
	if (n < 0)
	{
		if (ft_putnchar_fd('-', 1, 1) == -1)
			return (-1);
		n *= (-1);
	}
	if (n < 10)
	{
		if (ft_putnchar_fd(n + '0', 1, 1) == -1)
			return (-1);
	}
	else
	{
		if (ft_printf_putnbr(n / 10) == -1)
			return (-1);
		if (ft_putnchar_fd(n % 10 + '0', 1, 1) == -1)
			return (-1);
	}
	return (0);
}

int	ft_printf_number_length(int number)
{
	int	count;

	count = 0;
	if (number == 0)
		return (1);
	if (number == -2147483648)
		return (10);
	if (number < 0)
		number *= -1;
	while (number > 0)
	{
		count++;
		number /= 10;
	}
	return (count);
}

int	ft_printf_number_length_hex(t_log *log, unsigned int number)
{
	int	count;
	int	base_len;

	count = 0;
	base_len = 16;
	if (log->type == 'u')
		base_len = 10;
	if (number == 0)
		return (1);
	while (number > 0)
	{
		count++;
		number /= base_len;
	}
	return (count);
}

int	ft_printf_number_length_address(unsigned long number)
{
	int	count;

	count = 0;
	if (number == 0)
		return (1);
	while (number > 0)
	{
		count++;
		number /= 16;
	}
	return (count);
}
