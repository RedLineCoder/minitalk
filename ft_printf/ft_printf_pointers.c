/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:42:29 by moztop            #+#    #+#             */
/*   Updated: 2024/05/22 18:24:39 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static	int	ft_printf_address(unsigned long n, char *base, int count)
{
	if (n < (unsigned long)ft_strlen(base))
	{
		if (ft_putnchar_fd(base[n % ft_strlen(base)], 1, 1) == -1)
			return (-1);
	}
	else
	{
		if (ft_printf_address(n / ft_strlen(base), base, count) == -1)
			return (-1);
		if (ft_putnchar_fd(base[n % ft_strlen(base)], 1, 1) == -1)
			return (-1);
	}
	return (count);
}

int	ft_printf_pointers(unsigned long address)
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
