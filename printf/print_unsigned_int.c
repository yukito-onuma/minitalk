/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:32:13 by yonuma            #+#    #+#             */
/*   Updated: 2024/05/25 13:17:51 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned_int(unsigned int n)
{
	char	c;
	int		check;

	if (n >= 10)
	{
		check = print_unsigned_int(n / 10);
		if (check == -1)
			return (-1);
	}
	c = '0' + (n % 10);
	check = write(1, &c, 1);
	if (check == -1)
		return (-1);
	return (0);
}
