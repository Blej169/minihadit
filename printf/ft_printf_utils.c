/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblej <mblej@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:07:01 by mblej             #+#    #+#             */
/*   Updated: 2023/04/25 22:32:36 by mblej            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_print_str("(null)");
		return (6);
	}
	while (str[i])
	{
		ft_print_char(str[i]);
		i++;
	}
	return (i);
}

int	ft_print_nbr(int n)
{
	long	num;
	int		count;

	count = 0;
	num = n;
	if (num < 0)
	{
		count += ft_print_char('-');
		num *= -1;
	}
	if (num < 10)
		count += ft_print_char(num + '0');
	else
	{
		count += ft_print_nbr(num / 10);
		count += ft_print_nbr(num % 10);
	}
	return (count);
}

int	ft_print_unsigned(unsigned int n)
{
	long	num;
	int		count;

	count = 0;
	num = n;
	if (num < 10)
		count += ft_print_char(num + '0');
	else
	{
		count += ft_print_unsigned(num / 10);
		count += ft_print_unsigned(num % 10);
	}
	return (count);
}
