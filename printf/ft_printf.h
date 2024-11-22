/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:19:43 by yonuma            #+#    #+#             */
/*   Updated: 2024/05/25 12:59:12 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_write_nbr(int n);
int		ft_putnbr(int n);
int		return_percent(void);
int		ft_strlen(const char *str);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_printf(const char *format, ...);
int		return_int(int str);
int		return_chr(int c);
int		return_pointer(void *str);
int		print_unsigned_int(unsigned int n);
int		return_ten(unsigned int n);
int		return_str(char *str);
int		ft_format(va_list ap, const char str);
int		return_len_base(unsigned int n, char c);

#endif