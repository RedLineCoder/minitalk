/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:42:21 by moztop            #+#    #+#             */
/*   Updated: 2024/05/22 18:24:19 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf_char(char chr)
{
	return (ft_putnchar_fd(chr, 1, 1));
}

int	ft_printf_chars(char *str)
{
	if (str == NULL)
		return (ft_putnstr_fd("(null)", 1, 6));
	else
		return (ft_putnstr_fd(str, 1, ft_strlen(str)));
}
