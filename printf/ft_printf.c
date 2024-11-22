/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:22:46 by yonuma            #+#    #+#             */
/*   Updated: 2024/05/25 13:10:19 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list ap, const char str)
{
	int	result;

	result = 0;
	if (str == 'c')
		result += return_chr(va_arg(ap, int));
	else if (str == 's')
		result += return_str(va_arg(ap, char *));
	else if (str == 'p')
		result += return_pointer(va_arg(ap, void *));
	else if (str == 'd' || str == 'i')
		result += return_int(va_arg(ap, int));
	else if (str == 'u')
		result += return_ten(va_arg(ap, unsigned int));
	else if (str == 'x' || str == 'X')
		result += return_len_base(va_arg(ap, unsigned int), str);
	else if (str == '%')
		result += return_percent();
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		result;
	size_t	i;

	va_start(ap, format);
	i = 0;
	result = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			result += ft_format(ap, format[i + 1]);
			i++;
		}
		else
			result += return_chr(format[i]);
		if (result == -1)
			return (-1);
		i++;
	}
	va_end(ap);
	return (result);
}

// int	main(void)
// {
// 	int num;
// 	num = ft_printf("MAX: %p MIN : %p\n", LONG_MAX, LONG_MIN);
// 	printf("num1 : %d\n", num);
// 	num = printf("\001\002\007\v\010\f\r\n");
// 	printf("num2 : %d\n", num);
// 	return (0);
// }
