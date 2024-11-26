/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhurnik <hhurnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:34:33 by hhurnik           #+#    #+#             */
/*   Updated: 2024/05/31 19:03:22 by hhurnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_hex_up(int n)
{
	char	*str;

	str = (char *)malloc(3 * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 10)
		str[0] = n + '0';
	else
		str[0] = 'A' + (n - 10);
	str[1] = '\0';
	return (str);
}

int	ft_hex_up_additional(unsigned long n)
{
	int		hex_value;
	int		length;
	int		i;
	char	*temp;
	char	*hex_str;

	length = hex_number_size(n);
	i = length - 1;
	hex_str = (char *)malloc((length + 1) * sizeof(char));
	if (!hex_str)
		return (0);
	hex_str[length] = '\0';
	while (n != 0)
	{
		hex_value = n % 16;
		n = n / 16;
		temp = print_hex_up(hex_value);
		hex_str[i--] = temp[0];
		free(temp);
	}
	write(1, hex_str, length);
	free(hex_str);
	return (length);
}

int	ft_hex_up(unsigned long n)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		ft_hex_up_additional(n);
		return (hex_number_size(n));
	}
}
