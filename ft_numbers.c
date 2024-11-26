/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhurnik <hhurnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:43:59 by hhurnik           #+#    #+#             */
/*   Updated: 2024/06/03 16:59:58 by hhurnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	number_size(int n)
{
	unsigned int	length;

	length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		length++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char			*string;
	unsigned int	length;

	length = number_size(n);
	string = (char *)malloc(sizeof(char) * (length + 1));
	if (!string)
		return (NULL);
	if (n == 0)
		string[0] = '0';
	if (n < 0)
		string[0] = '-';
	string[length] = '\0';
	while (n != 0)
	{
		if (n > 0)
			string[--length] = n % 10 + '0';
		else
		{
			string[length - 1] = n % 10 * -1 + '0';
			length--;
		}
		n = n / 10;
	}
	return (string);
}

char	*ft_utoa_additional(unsigned int n)
{
	char			*string;
	unsigned int	temp_n;

	temp_n = n;
	if (temp_n == 0)
	{
		string = (char *)malloc(2 * sizeof(char));
		if (!string)
			return (NULL);
		string[0] = '0';
		string[1] = '\0';
		return (string);
	}
	else
		return (NULL);
}

char	*ft_utoa(unsigned int n)
{
	char			*string;
	unsigned int	length;
	unsigned int	temp_n;

	temp_n = n;
	length = 0;
	if (temp_n == 0)
	{
		return (ft_utoa_additional(n));
	}
	while (temp_n != 0)
	{
		temp_n /= 10;
		length++;
	}
	string = (char *)malloc(sizeof(char) * (length + 1));
	if (!string)
		return (NULL);
	string[length] = '\0';
	while (n != 0)
	{
		string[--length] = n % 10 + '0';
		n = n / 10;
	}
	return (string);
}
