/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:27:10 by yonuma            #+#    #+#             */
/*   Updated: 2024/11/01 19:57:43 by yonuma           ###   ########.fr       */
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

int	check_one(int signum, int digit)
{
	// static int	count = 0;
	static bool	check_byte = true;
	// static int	check_digit = 1;

	if (digit < 5)
	{
		if (signum == SIGUSR1 && check_byte)
		{
			printf("aaan\n");
			return (1);
		}
		else
			check_byte = false;
	}
	return (0);
}

// void	check_unicode(wchar_t str)
// {
// 	unsigned char utf8[3];

//     utf8[0] = 0xE0 | ((str >> 12) & 0x0F);
//     utf8[1] = 0x80 | ((str >> 6) & 0x3F);
//     utf8[2] = 0x80 | (str & 0x3F);
//     printf("UTF-8 Encoding: %02X %02X %02X\n", utf8[0], utf8[1], utf8[2]);
//     printf("Character: %c\n", str);
// }

// void check_unicode(wchar_t str)
// {
//     // unsigned char utf8[5]; // 4バイト + 終端のヌルバイト
//     // int num_bytes = 0;

//     // // wchar_t から UTF-8 への変換
//     // if (str < 0x80) {
//     //     utf8[0] = str & 0x7F;
//     //     num_bytes = 1;
//     // } else if (str < 0x800) {
//     //     utf8[0] = 0xC0 | ((str >> 6) & 0x1F);
//     //     utf8[1] = 0x80 | (str & 0x3F);
//     //     num_bytes = 2;
//     // } else if (str < 0x10000) {
//     //     utf8[0] = 0xE0 | ((str >> 12) & 0x0F);
//     //     utf8[1] = 0x80 | ((str >> 6) & 0x3F);
//     //     utf8[2] = 0x80 | (str & 0x3F);
//     //     num_bytes = 3;
//     // } else {
//     //     utf8[0] = 0xF0 | ((str >> 18) & 0x07);
//     //     utf8[1] = 0x80 | ((str >> 12) & 0x3F);
//     //     utf8[2] = 0x80 | ((str >> 6) & 0x3F);
//     //     utf8[3] = 0x80 | (str & 0x3F);
//     //     num_bytes = 4;
//     // }

//     // // UTF-8文字列の終端
//     // utf8[num_bytes] = '\0';

//     // // UTF-8エンコーディングを表示
//     // printf("UTF-8 Encoding: ");
//     // for (int i = 0; i < num_bytes; i++) {
//     //     printf("%02X ", utf8[i]); // unsigned char型として表示
//     // }
//     // printf("\n");

//     // // 元のwchar_t文字を表示
//     // printf("Character: %lc\n", str); // %lcを使用してwchar_tを表示
// }

void	handler(int signum)
{
	printf("%d\n",signum);
	static wchar_t 	c = 0;
	static unsigned int		digit = 0;
	static unsigned int		byte = 0;

	if (digit != 0)
		c = c << 1;
	if (signum == SIGUSR1)
		c |= 1;
	digit++;
	byte += check_one(signum, digit);
    printf("digit: %d, 8*byte: %d\n", digit, 8 * byte);  // debug
	if (8 * byte == digit)
	{
		printf("aaaaaa\n");
		printf("check: %d\n", byte);
		// check_unicode(c);
		write(1, &c, byte);
		c = 0;
		digit = 0;
		byte = 0;
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
