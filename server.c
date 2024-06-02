/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:27:56 by yonuma            #+#    #+#             */
/*   Updated: 2024/06/01 15:27:56 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	handler(int signum)
{
	static char	c = 0;
	static int	digit = 0;

	if (digit != 0)
		c = c << 1;
	if (signum == SIGUSR1)
		c |= 1;
	digit++;
	if (digit == 8)
	{
		write(1, &c, 1);
		c = 0;
		digit = 0;
	}
}

int	main(void)
{
	printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
