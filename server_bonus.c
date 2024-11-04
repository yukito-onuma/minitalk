/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:27:10 by yonuma            #+#    #+#             */
/*   Updated: 2024/11/04 20:39:33 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <wchar.h>
#include <unistd.h>
#include <stdbool.h>
#include "minitalk.h"

int check_utf8(unsigned char ch) {
    if (ch < 0x80) {
        return 1;
    } else if ((ch & 0xE0) == 0xC0) {
        return 2;
    } else if ((ch & 0xF0) == 0xE0) {
        return 3;
    } else if ((ch & 0xF8) == 0xF0) {
        return 4;
    } else {
        return -1;
    }
}

void handler(int signum, siginfo_t *info, void *context)
{
    static unsigned char    c = 0;
    static unsigned int     digit = 0;
    static unsigned int     byte = 0;
    static pid_t            client_pid = 0;

    if (client_pid == 0)
        client_pid = info->si_pid;
    if (digit != 0)
        c = c << 1;
    if (signum == SIGUSR1)
        c |= 1;
    digit++;
    if (digit == 1)
        byte = check_utf8(c);
    if (8 * byte == digit)
    {
        write(1, &c, byte);
        kill(client_pid, SIGUSR1);
        c = 0;
        digit = 0;
        byte = 0;
    }
}

int main(void)
{
    struct sigaction sa;
    
    printf("Server PID: %d\n", getpid());
    sa.sa_sigaction = handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    
    while (1)
        pause();
    
    return 0;
}
