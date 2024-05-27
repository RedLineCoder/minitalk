/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:14:36 by moztop            #+#    #+#             */
/*   Updated: 2024/02/28 22:19:22 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>

int	ft_printf_chars_print(t_log *log, char *str)
{
	if (str == NULL)
		return (ft_putnstr_fd("(null)", 1, log->precision));
	else
		return (ft_putnstr_fd(str, 1, log->precision));
}

int	ft_strlen_recursive(const char *str)
{
	if (*str == 0)
		return (0);
	return (1 + ft_strlen_recursive(str + 1));
}

int	ft_putnchar_fd(char c, int fd, size_t n)
{
	int	count;

	count = n;
	while (n--)
	{
		if (write(fd, &c, 1) == -1)
			return (-1);
	}
	return (count);
}

int	ft_putnstr_fd(char *s, int fd, size_t n)
{
	if (write(fd, s, n) == -1)
		return (-1);
	return (n);
}

int	ft_printf_zero_space_flags(t_log *log)
{
	if (!log->minus && log->width > log->precision && log->zero)
		return (ft_putnchar_fd('0', 1, log->width - log->precision));
	else if (!log->minus && log->width > log->precision)
		return (ft_putnchar_fd(' ', 1, log->width - log->precision));
	return (0);
}
