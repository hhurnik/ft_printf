/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhurnik <hhurnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:26:02 by hhurnik           #+#    #+#             */
/*   Updated: 2024/05/29 18:43:11 by hhurnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_unsigned(va_list arguments)
{
	char			*num_str;
	char			*original_num_str;
	int				counter;
	unsigned int	varg;

	varg = va_arg(arguments, unsigned int);
	num_str = ft_utoa(varg);
	original_num_str = num_str;
	counter = 0;
	while (*num_str)
	{
		ft_printchar(*num_str);
		counter++;
		num_str++;
	}
	free(original_num_str);
	return (counter);
}

int	handle_void(va_list arguments)
{
	unsigned long	ptr_value;
	int				count;

	ptr_value = (unsigned long)va_arg(arguments, void *);
	if (ptr_value == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		count = ft_hex(ptr_value);
		return (count + 2);
	}
}

int	handle_hex(va_list arguments)
{
	return (ft_hex(va_arg(arguments, unsigned int)));
}

int	handle_char(va_list arguments)
{
	ft_printchar(va_arg(arguments, int));
	return (1);
}

int	handle_string(va_list arguments)
{
	char	*str;
	int		count;

	str = va_arg(arguments, char *);
	if (str)
	{
		count = 0;
		while (*str)
		{
			ft_printchar(*str++);
			count++;
		}
		return (count);
	}
	else
	{
		write(1, "(null)", 6);
		return (6);
	}
}
