/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:04:02 by marvin            #+#    #+#             */
/*   Updated: 2024/05/27 12:04:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>


void handler(int signum)
{
    char    c;
    int     digit;

    c = c << 1;
    if (signum == SIGUSR1)
        c |= 1 << digit;
    digit++;
    if (digit == 8)
    {
        write(1, &c, 1);
        c = 0;
        digit = 0;
    }
}

int main(void)
{

    printf("Server PID: %d\n", getpid());
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    return 0;
}