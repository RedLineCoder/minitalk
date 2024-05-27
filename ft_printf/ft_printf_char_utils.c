/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:23:46 by moztop            #+#    #+#             */
/*   Updated: 2024/02/28 22:17:22 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

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
