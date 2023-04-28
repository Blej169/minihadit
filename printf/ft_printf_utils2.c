/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblej <mblej@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:16:02 by mblej             #+#    #+#             */
/*   Updated: 2022/12/19 22:27:52 by mblej            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned long num, char c)
{
	const char	*hex;

	hex = "0123456789abcdef";
	if (c == 'X')
		hex = "0123456789ABCDEF";
	write(1, &hex[num], 1);
	return (1);
}

int	ft_print_hex(unsigned long nb, char c)
{
	int	cnt;

	cnt = 0;
	if (nb < 16)
		cnt += ft_hex(nb, c);
	else
	{
		cnt += ft_print_hex(nb / 16, c);
		cnt += ft_hex(nb % 16, c);
	}
	return (cnt);
}

int	ft_print_ptr(void *ptr)
{
	int				length;
	unsigned long	addr;

	length = 0;
	ft_print_str("0x");
	addr = (unsigned long)ptr;
	length += ft_print_hex(addr, 'x');
	return (length + 2);
}
