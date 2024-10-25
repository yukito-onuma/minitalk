/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:27:10 by yonuma            #+#    #+#             */
/*   Updated: 2024/10/25 20:24:19 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <wchar.h>
#include <unistd.h>
#include <stdbool.h>
#include "minitalk.h"

// void	handler(int signum)
// {
// 	static char	c = 0;
// 	static int	digit = 0;

// 	if (digit != 0)
// 		c = c << 1;
// 	if (signum == SIGUSR1)
// 		c |= 1;
// 	digit++;
// 	if (digit == 8)
// 	{
// 		write(1, &c, 1);
// 		c = 0;
// 		digit = 0;
// 	}
// }

int	check_one(int signum)
{
	static int	count = 0;
	static bool	check_sig = true;
	
	if (signum == SIGUSR1 && check_sig)
		count++;
	else
	{
		check_sig = false;
		return (count);
	}
	return (0);
}

void	check_unicode(char str)
{
	unsigned char utf8[3];

    utf8[0] = 0xE0 | ((str >> 12) & 0x0F);
    utf8[1] = 0x80 | ((str >> 6) & 0x3F);
    utf8[2] = 0x80 | (str & 0x3F);
    printf("UTF-8 Encoding: %02X %02X %02X\n", utf8[0], utf8[1], utf8[2]);
    printf("Character: %s\n", utf8);
}

void	handler(int signum)
{
	printf("%d\n",signum);
	static wchar_t 	c = 0;
	static int		digit = 0;
	static int		byte = 0;

	if (digit != 0)
		c = c << 1;
	if (signum == SIGUSR1)
		c |= 1;
	digit++;
	byte = check_one(signum);
    printf("digit: %d, 8*byte: %d\n", digit, 8 * byte);  // debug
	if (8 * byte == digit)
	{
		printf("aaaaaa\n");
		printf("check: %d\n", byte);
		check_unicode(c);
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
