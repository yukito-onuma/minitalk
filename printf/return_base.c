/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:12:06 by yonuma            #+#    #+#             */
/*   Updated: 2024/05/11 16:58:44 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	return_base(unsigned int n, int count, char c)
{
	int	result;
	int	num;

	if (n >= 16)
	{
		count = return_base(n / 16, count + 1, c);
		if (count == -1)
			return (-1);
	}
	if (n % 16 > 9)
	{
		if (c == 'x')
			result = n % 16 - 10 + 'a';
		if (c == 'X')
			result = n % 16 - 10 + 'A';
	}
	else
		result = n % 16 + '0';
	num = write(1, &result, 1);
	if (num == -1)
		return (-1);
	return (count);
}

int	return_len_base(unsigned int n, char c)
{
	int	check;

	check = return_base(n, 1, c);
	if (check == -1)
		return (-1);
	return (check);
}

// int	main(void)
// {
// 	return_len_base(14);
// }
