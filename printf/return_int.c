/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:30:36 by yonuma            #+#    #+#             */
/*   Updated: 2024/05/25 13:03:09 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	return_int(int str)
{
	int	digit;
	int	check;

	digit = 0;
	check = ft_putnbr(str);
	if (check == -1)
		return (-1);
	if (str < 0)
		digit++;
	if (str == 0)
		digit++;
	while (str != 0)
	{
		str /= 10;
		digit++;
	}
	return (digit);
}
