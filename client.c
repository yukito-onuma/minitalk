/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/06/01 15:27:50 by yonuma            #+#    #+#             */
/*   Updated: 2024/06/01 15:27:50 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_skip_char = 1;

void	send_char(int pid, char c)
{
	int	digit;

	digit = 7;
	while (digit >= 0)
	{
		g_skip_char = 0;
		if (c & (1 << digit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		digit--;
		while (!g_skip_char)
			pause();
		usleep(500);
	}
}

void	send_str(int pid, char *str)
{
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
}

void	sigusr1_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("OK!\n");
		g_skip_char = 1;
	}
	if (sig == SIGUSR2)
		ft_printf("KO!\n");
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	if (pid < 0 || pid > INT_MAX)
		return (0);
	sa.sa_handler = sigusr1_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("sigaction");
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("sigaction");
	}
	send_str(pid, argv[2]);
	return (0);
}
