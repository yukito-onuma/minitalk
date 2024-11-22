/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:34:30 by yonuma            #+#    #+#             */
/*   Updated: 2024/05/25 12:53:50 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_pointer(void *n, int *count)
{
	char			*hex_digits;
	unsigned long	ui;
	int				check;

	*count += 1;
	ui = (unsigned long)n;
	hex_digits = "0123456789abcdef";
	if (ui >= 16)
		print_pointer((void *)(ui / 16), count);
	check = write(1, &hex_digits[ui % 16], 1);
	if (check == -1)
		return (-1);
	return (0);
}

int	return_pointer(void *n)
{
	int	count;
	int	check;

	count = 2;
	check = write(1, "0x", 2);
	if (check == -1)
		return (-1);
	check = print_pointer(n, &count);
	if (check == -1)
		return (-1);
	return (count);
}
