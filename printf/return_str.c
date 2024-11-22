/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:33:12 by yonuma            #+#    #+#             */
/*   Updated: 2024/05/25 13:11:24 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	return_str(char *str)
{
	int	len;
	int	check;

	len = 0;
	if (!str)
	{
		check = write(1, "(null)", 6);
		if (check == -1)
			return (-1);
		return (6);
	}
	while (str[len] != '\0')
		len++;
	check = ft_putstr(str);
	if (check == -1)
		return (-1);
	return (len);
}
