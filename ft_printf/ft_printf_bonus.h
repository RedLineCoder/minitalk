/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:36:37 by moztop            #+#    #+#             */
/*   Updated: 2024/02/28 22:39:04 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>

/* 
The structure of a variable given to printf function
%[parameter][flags][width][.precision][length]type
*/

typedef struct s_log
{
	int		minus;
	int		plus;
	int		width;
	int		precision;
	int		dot;
	char	type;
	int		zero;
	int		space;
	int		sharp;
}	t_log;

/* String containing printf's parameters */
# define TYPE		"cspdiuxX%"

/* Lower hexadecimal base */
# define HEXALOW	"0123456789abcdef"

/* Upper hexadecimal base */
# define HEXAUP		"0123456789ABCDEF"

/* Decimal base */
# define DECIMAL	"0123456789"

/* BASE */

int	ft_printf(const char *input, ...);
int	ft_printf_parse(char *start, va_list *args);
int	ft_printf_print_type(t_log *log, va_list *args);
int	ft_printf_char_bonus(t_log *log, char chr);
int	ft_printf_chars_bonus(t_log *log, char *str);
int	ft_printf_number_bonus(t_log *log, int number);
int	ft_printf_base_bonus(t_log *log, unsigned int number);
int	ft_printf_pointers_bonus(t_log *log, unsigned long address);

/* UTILS */

int	ft_printf_chars_print(t_log *log, char *str);
int	ft_strlen_recursive(const char *str);
int	ft_putnchar_fd(char c, int fd, size_t n);
int	ft_putnstr_fd(char *s, int fd, size_t n);
int	ft_printf_zero_space_flags(t_log *log);
int	ft_printf_number_flags(t_log *log, int number, int len);
int	ft_printf_hex_flags(t_log *log, unsigned int number, int len);
int	ft_printf_putnbr(int n);
int	ft_printf_number_length(int number);
int	ft_printf_number_length_hex(t_log *log, unsigned int number);
int	ft_printf_number_length_address(unsigned long number);

#endif