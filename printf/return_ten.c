/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_ten.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:34:00 by yonuma            #+#    #+#             */
/*   Updated: 2024/05/25 13:20:36 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	return_ten(unsigned int n)
{
	int	length;
	int	check;

	length = 0;
	check = print_unsigned_int(n);
	if (check == -1)
		return (-1);
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}
