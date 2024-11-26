/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhurnik <hhurnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:54:17 by hhurnik           #+#    #+#             */
/*   Updated: 2024/06/03 16:03:38 by hhurnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_hex_up(va_list arguments)
{
	return (ft_hex_up(va_arg(arguments, unsigned int)));
}

int	handle_format_specifier(char specifier, va_list arguments)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count = handle_char(arguments);
	else if (specifier == 's')
		count = handle_string(arguments);
	else if (specifier == 'd' || specifier == 'i')
		count = handle_decimal(arguments);
	else if (specifier == 'x')
		count = handle_hex(arguments);
	else if (specifier == 'X')
		count = handle_hex_up(arguments);
	else if (specifier == 'p')
		count = handle_void(arguments);
	else if (specifier == 'u')
		count = handle_unsigned(arguments);
	else if (specifier == '%')
	{
		ft_printchar('%');
		count = 1;
	}
	else
		return (-1);
	return (count);
}

int	handle_format_string(const char *format, va_list arguments)
{
	int	count;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += handle_format_specifier(*format, arguments);
			format++;
		}
		else
		{
			ft_printchar(*format);
			count++;
			format++;
		}
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		count;

	count = 0;
	va_start(arguments, format);
	count = handle_format_string(format, arguments);
	va_end(arguments);
	return (count);
}
