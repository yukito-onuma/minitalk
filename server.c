/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:27:56 by yonuma            #+#    #+#             */
/*   Updated: 2024/11/22 16:38:27 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_utf8(unsigned char ch)
{
	if (ch < 0x80)
		return (1);
	else if ((ch & 0xE0) == 0xC0)
		return (2);
	else if ((ch & 0xF0) == 0xE0)
		return (3);
	else if ((ch & 0xF8) == 0xF0)
		return (4);
	else
		return (-1);
}

void	process_signal(int signum, unsigned char *c, int *digit, pid_t pid)
{
	if (*digit != 0)
		c[*digit / 8] <<= 1;
	if (signum == SIGUSR1)
		c[*digit / 8] |= 1;
	kill(pid, SIGUSR1);
	(*digit)++;
}

void	process_data(unsigned char *c, int *digit, int *byte, pid_t pid)
{
	if (*digit % 8 == 0)
	{
		if (*digit == 8)
			*byte = check_utf8(c[0]);
		if (*byte == -1)
		{
			ft_memset(c, 0, 4);
			kill(pid, SIGUSR2);
			*digit = 0;
			*byte = 0;
			return ;
		}
		if (8 * (*byte) == *digit)
		{
			write(1, c, *byte);
			ft_memset(c, 0, 4);
			*digit = 0;
			*byte = 0;
		}
	}
}

void	handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c[4] = {0};
	static int				digit = 0;
	static int				byte = 0;

	(void)context;
	process_signal(signum, c, &digit, info->si_pid);
	process_data(c, &digit, &byte, info->si_pid);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
