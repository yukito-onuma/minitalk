/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:57:36 by marvin            #+#    #+#             */
/*   Updated: 2024/05/27 11:57:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void    send_char(int pid, char c)
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

void    send_str(int pid, char *str)
{
    while (*str)
    {
        send_char(pid, *str);
        str++;
    }
}

int main(int argc, char **argv)
{
    int pid;

    if (argc != 3)
        return (0);
    pid = atoi(argv[1]);
    send_str(pid, argv[2]);
}