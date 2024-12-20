/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:31:04 by yonuma            #+#    #+#             */
/*   Updated: 2024/11/22 16:26:45 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <limits.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	ft_bzero(void *b, size_t len);
void	*ft_memset(void *ptr, int value, size_t num);
int		ft_atoi(const char *str);
int		ft_printf(const char *format, ...);
int		return_int(int str);
int		return_chr(int c);

#endif