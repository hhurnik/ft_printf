/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhurnik <hhurnik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:02:49 by hhurnik           #+#    #+#             */
/*   Updated: 2024/06/07 12:37:27 by hhurnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int					number_size(int n);
void				ft_printchar(char arg_char);
int					hex_number_size(unsigned long n);
char				*print_hex(int n);
int					ft_hex(unsigned long n);
char				*ft_itoa(int n);
char				*print_hex(int n);
char				*print_hex_up(int n);
int					ft_hex_up(unsigned long n);
char				*ft_utoa(unsigned int n);
int					handle_char(va_list arguments);
int					handle_string(va_list arguments);
int					handle_decimal(va_list arguments);
int					handle_hex(va_list arguments);
int					handle_void(va_list arguments);
int					handle_unsigned(va_list arguments);
int					handle_hex_up(va_list arguments);
int					handle_format_specifier(char specifier, va_list arguments);
int					handle_format_string(const char *format, va_list arguments);
int					ft_printf(const char *format, ...);
int					ft_hex_additional(unsigned long n);
int					ft_hex_up_additional(unsigned long n);
char				*ft_utoa_additional(unsigned int n);

#endif
