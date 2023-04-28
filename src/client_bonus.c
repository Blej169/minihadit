/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblej <mblej@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:28:29 by mblej             #+#    #+#             */
/*   Updated: 2023/04/26 18:17:38 by mblej            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(const char *str)
{
	unsigned long int	r;
	int					i;
	int					ng;

	i = 0;
	ng = 1;
	r = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			ng *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = str[i] - '0' + (r * 10);
		i++;
	}
	return (r * ng);
}

void	receive(int s)
{
	static int	i;

	if (s == SIGUSR2)
	{
		i++;
		return ;
	}
	else if (s == SIGUSR1)
	{
		if (ft_printf("message received\n") == -1)
			exit(EXIT_FAILURE);
		exit(EXIT_SUCCESS);
	}
}

void	send_char(unsigned char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 128)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(EXIT_FAILURE);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(EXIT_FAILURE);
		}
		c <<= 1;
		i++;
		pause();
		usleep(400);
	}
}

void	send_text(int pid, char *str)
{
	while (*str)
	{
		send_char(*str, pid);
		str++;
	}
	send_char('\0', pid);
}

int	main(int ac, char **av)
{
	int	s_pid;

	signal(SIGUSR2, &receive);
	signal(SIGUSR1, &receive);
	if (ac == 3)
	{
		s_pid = ft_atoi(av[1]);
		if (kill(s_pid, 0) == -1)
		{
			write(1, "pid not valid", 14);
			exit(-1);
		}
		send_text(s_pid, av[2]);
	}
	else
	{
		write(1, "args not valid", 15);
		return (EXIT_FAILURE);
	}
}
