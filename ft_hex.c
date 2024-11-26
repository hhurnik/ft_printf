/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhurnik <hhurnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:03:38 by hhurnik           #+#    #+#             */
/*   Updated: 2024/05/31 19:34:46 by hhurnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_number_size(unsigned long n)
{
	int	size;

	size = 0;
	while (n != 0)
	{
		n /= 16;
		size++;
	}
	return (size);
}

char	*print_hex(int n)
{
	char	*str;

	str = (char *)malloc(3 * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 10)
		str[0] = n + '0';
	else
		str[0] = 'a' + (n - 10);
	str[1] = '\0';
	return (str);
}

int	ft_hex_additional(unsigned long n)
{
	int		hex_value;
	int		index;
	int		length;
	char	*temp;
	char	*hex_str;

	length = hex_number_size(n);
	index = length - 1;
	hex_str = (char *)malloc((length + 1) * sizeof(char));
	if (!hex_str)
		return (0);
	hex_str[length] = '\0';
	while (n != 0)
	{
		hex_value = n % 16;
		n = n / 16;
		temp = print_hex(hex_value);
		hex_str[index--] = temp[0];
		free(temp);
	}
	write(1, hex_str, length);
	free(hex_str);
	return (length);
}

int	ft_hex(unsigned long n)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		ft_hex_additional(n);
		return (hex_number_size(n));
	}
}

int	handle_decimal(va_list arguments)
{
	char	*num_str;
	char	*original_num_str;
	int		counter;

	num_str = ft_itoa(va_arg(arguments, int));
	if (!num_str)
		return (0);
	original_num_str = num_str;
	counter = 0;
	while (*num_str)
	{
		ft_printchar(*num_str++);
		counter++;
	}
	free(original_num_str);
	return (counter);
}
