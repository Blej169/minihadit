/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblej <mblej@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:15:15 by mblej             #+#    #+#             */
/*   Updated: 2023/04/25 22:33:04 by mblej            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_ptr(void *ptr);
int	ft_print_nbr(int i);
int	ft_print_unsigned(unsigned int i);
int	ft_formats(va_list args, const char format);
int	ft_print_hex(unsigned long nb, char c);
#endif