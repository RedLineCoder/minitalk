/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:27:40 by moztop            #+#    #+#             */
/*   Updated: 2024/05/22 18:24:32 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"

static	void	ft_printf_log_init(t_log *log)
{
	log->minus = 0;
	log->type = 0;
	log->plus = 0;
	log->precision = 0;
	log->dot = 0;
	log->sharp = 0;
	log->space = 0;
	log->width = 0;
	log->zero = 0;
}

static	void	ft_printf_parse_flags(t_log *log, char *start)
{
	while (*start != '.' && !ft_strchr(TYPE, *start) && *start)
	{
		if (*start == '+')
			log->plus = 1;
		if (*start == '-')
			log->minus = 1;
		if (*start == '#')
			log->sharp = 1;
		if (*start == '0' && !ft_isdigit(*(start - 1)))
			log->zero = 1;
		if (*start == ' ')
			log->space = 1;
		start++;
	}
}

static	void	ft_printf_parse_width(t_log *log, char	*start, va_list	*args)
{
	size_t	length;

	length = 0;
	while (*start != '.' && !ft_strchr(TYPE, *start) && *start)
	{
		if ((ft_isdigit(*start) && *start > '0') || *start == '*')
		{
			if (*start == '*')
				log->width = va_arg(*args, int);
			else
			{
				log->width = ft_atoi(start);
				while (ft_isdigit(*start))
					start++;
			}
		}
		else
			start++;
	}
}

static	void	ft_printf_parse_prec(t_log *log, char *start, va_list *args)
{
	size_t	length;

	length = 0;
	while (!ft_strchr(TYPE, *start) && *start)
	{
		if ((ft_isdigit(*start) && *start > '0') || *start == '*')
		{
			if (*start == '*')
				log->precision = va_arg(*args, int);
			else
			{
				log->precision = ft_atoi(start);
				while (ft_isdigit(*start))
					start++;
			}
		}
		else
			start++;
	}
}

int	ft_printf_parse(char *start, va_list *args)
{
	t_log	log;

	ft_printf_log_init(&log);
	ft_printf_parse_flags(&log, start);
	ft_printf_parse_width(&log, start, args);
	while (*start != '.' && !ft_strchr(TYPE, *start) && *start)
		start++;
	if (*start == '.')
	{
		log.dot = 1;
		ft_printf_parse_prec(&log, start, args);
	}
	while (!ft_strchr(TYPE, *start) && *start)
		start++;
	log.type = *start;
	return (ft_printf_print_type(&log, args));
}
