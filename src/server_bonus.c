/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblej <mblej@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 22:15:34 by mblej             #+#    #+#             */
/*   Updated: 2023/04/26 23:11:09 by mblej            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	reset(char *c, int *pd1, int *pd2, int *bit)
{
	if (*pd1 != *pd2)
	{
		*pd1 = *pd2;
		*c = 0;
		*bit = 0;
	}
}

void	printing(char *c, int *info, int *bit)
{
	ft_printf("%c", *c);
	*bit = 0;
	if (*c == '\0')
	{
		*c = 0;
		kill(*info, SIGUSR1);
	}
}

void	shandler(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static int	clpid;
	static int	curpid;
	static char	c;

	(void)context;
	if (!clpid)
		clpid = info->si_pid;
	curpid = info->si_pid;
	reset(&c, &clpid, &curpid, &bit);
	c = c | (sig == SIGUSR2);
	bit++;
	if (bit == 8)
		printing(&c, &clpid, &bit);
	c <<= 1;
	usleep(100);
	kill(clpid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	dec;
	int					pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	dec.sa_sigaction = shandler;
	dec.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &dec, 0);
		sigaction(SIGUSR2, &dec, 0);
		pause();
	}
}
