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

#include "minitalk.h"

int check_utf8(unsigned char ch) {
    if (ch < 0x80)
        return 1;
    else if ((ch & 0xE0) == 0xC0)
        return 2;
    else if ((ch & 0xF0) == 0xE0)
        return 3;
    else if ((ch & 0xF8) == 0xF0)
        return 4;
    else
        return -1;
}

void handler(int signum, siginfo_t *info, void *context)
{
    static unsigned char c[4] = {0};
    static int digit = 0;
    static int byte = 0;

    (void)context;
    if (digit != 0)
        c[digit / 8] <<= 1;
    if (signum == SIGUSR1)
        c[digit / 8] |= 1;
    kill(info->si_pid, SIGUSR1);
    digit++;
    // printf("byte: %d, digit: %d\n", byte, digit);
    if (digit % 8 == 0)
    {
        if (digit == 8)
            byte = check_utf8(c[0]);
        if (byte == -1)
        {
            memset(c, 0, sizeof(c));
            kill(info->si_pid, SIGUSR2);
            digit = 0;
            byte = 0;
            return;
        }
        if (8 * byte == digit)
        {
            write(1, c, byte);
            // kill(info->si_pid, SIGUSR1);
            memset(c, 0, sizeof(c)); // memset注意！
            digit = 0;
            byte = 0;
        }
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
    return (0);
}
