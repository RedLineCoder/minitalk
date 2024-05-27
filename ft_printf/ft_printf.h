/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:56:04 by moztop            #+#    #+#             */
/*   Updated: 2024/02/28 22:44:16 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

typedef struct s_log
{
	char	type;
}	t_log;

/* String containing printf's parameters */
# define TYPE		"cspdiuxX%"

/* Lower hexadecimal base */
# define HEXALOW	"0123456789abcdef"

/* Upper hexadecimal base */
# define HEXAUP		"0123456789ABCDEF"

/* Decimal base */
# define DECIMAL	"0123456789"

/* MANDATORY */

int	ft_printf(const char *input, ...);
int	ft_printf_parse(char *start, va_list *args);
int	ft_printf_print_type(t_log *log, va_list *args);
int	ft_printf_char(char chr);
int	ft_printf_chars(char *str);
int	ft_printf_number(int number);
int	ft_printf_base(t_log *log, unsigned int number);
int	ft_printf_pointers(unsigned long address);

/* UTILS */

int	ft_putnchar_fd(char c, int fd, size_t n);
int	ft_putnstr_fd(char *s, int fd, size_t n);
int	ft_printf_putnbr(int n);
int	ft_printf_number_length(int number);
int	ft_printf_number_length_hex(t_log *log, unsigned int number);
int	ft_printf_number_length_address(unsigned long number);

#endif