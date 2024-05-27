/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:56:10 by moztop            #+#    #+#             */
/*   Updated: 2024/05/22 18:24:42 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf_print_type(t_log *log, va_list *args)
{
	int	count;

	count = 0;
	if (log->type == '%')
		count = ft_printf_char('%');
	if (log->type == 'c')
		count = ft_printf_char(va_arg(*args, int));
	if (log->type == 's')
		count = ft_printf_chars(va_arg(*args, char *));
	if (log->type == 'x' || log->type == 'X' || log->type == 'u')
		count = ft_printf_base(log, va_arg(*args, unsigned int));
	if (log->type == 'd' || log->type == 'i')
		count = ft_printf_number(va_arg(*args, int));
	if (log->type == 'p')
		count = ft_printf_pointers(va_arg(*args, unsigned long));
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		count;
	int		temp;

	va_start(args, input);
	temp = 0;
	count = 0;
	while (*input)
	{
		if (*input == '%')
		{
			temp = ft_printf_parse((char *)(++input), &args);
			while (!ft_strchr(TYPE, *input) && *input)
				input++;
		}
		else
			temp = ft_putnchar_fd(*input, 1, 1);
		if (temp == -1)
			return (-1);
		count += temp;
		input++;
	}
	va_end(args);
	return (count);
}
