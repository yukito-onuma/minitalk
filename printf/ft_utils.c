/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:22:35 by yonuma            #+#    #+#             */
/*   Updated: 2024/05/25 13:17:19 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_nbr(int n)
{
	char	c;
	int		check;

	if (n < 0)
	{
		check = write(1, "-", 1);
		if (check == -1)
			return (-1);
		n *= -1;
	}
	if (n > 9)
	{
		check = ft_write_nbr(n / 10);
		if (check == -1)
			return (-1);
	}
	c = '0' + (n % 10);
	check = write(1, &c, 1);
	if (check == -1)
		return (-1);
	return (0);
}

int	ft_putnbr(int n)
{
	int	check;

	if (n == -2147483648)
	{
		check = write(1, "-2147483648", 11);
		if (check == -1)
			return (-1);
		return (0);
	}
	else
		return (ft_write_nbr(n));
}

int	ft_putchar(char c)
{
	int	num;

	num = write(1, &c, 1);
	if (num == -1)
		return (-1);
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	size_t	size;
	size_t	i;
	int		check;

	size = ft_strlen(s);
	i = 0;
	while (i < size)
	{
		check = ft_putchar(s[i]);
		if (check == -1)
			return (-1);
		i++;
	}
	return (0);
}
