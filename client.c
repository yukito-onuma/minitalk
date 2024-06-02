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

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void	send_char(int pid, char c)
{
	int digit;

	digit = 7;
	while (digit >= 0)
	{
		if (c & (1 << digit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		digit--;
		usleep(50);
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

int	main(int argc, char **argv)
{
	int pid;

	if (argc != 3)
		return (0);
	pid = atoi(argv[1]); // ここ普通のatoi使っているから注意
	if (pid <= 0)
		return (0);
	send_str(pid, argv[2]);
}
