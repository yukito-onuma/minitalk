/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:26:49 by yonuma            #+#    #+#             */
/*   Updated: 2024/11/04 20:33:17 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t skip_char = 0;

void	send_char(int pid, char c)
{
	int digit;

	digit = 7;
	while (digit >= 0)
	{
		if (skip_char)
			return;
		if (c & (1 << digit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		digit--;
		usleep(1400);
	}
}

void	send_str(int pid, char *str)
{
	while (*str)
	{
		if (!skip_char)
			send_char(pid, *str);
		str++;
		skip_char = 0;
	}
}

void	sigusr1_handler(int sig)
{
	if (sig == SIGUSR1)
		printf("OK!\n");
	if (sig == SIGUSR2)
	{
		printf("KO!\n");
		skip_char = 1;
	}
}

int	main(int argc, char **argv)
{
	int pid;
	struct sigaction sa;

	if (argc != 3)
		return (0);
	pid = atoi(argv[1]); //ここ普通のatoi 使っているから注意
	if (pid <= 0)
		return (0);
	sa.sa_handler = sigusr1_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send_str(pid, argv[2]);

	return (0);
}
