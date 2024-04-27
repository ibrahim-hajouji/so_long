/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 08:32:39 by ihajouji          #+#    #+#             */
/*   Updated: 2024/04/21 13:01:49 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format(va_list args, char c)
{
	int	printf_length;

	printf_length = 0;
	if (c == 'c')
		printf_length += ft_putchar(va_arg(args, int));
	else if (c == 's')
		printf_length += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		printf_length += ft_putnbr(va_arg(args, int));
	else if (c == '%')
		printf_length += ft_putchar('%');
	else
		printf_length += ft_putchar(c);
	return (printf_length);
}

int	ft_printf(const char *str, ...)
{
	int				i;
	va_list			args;
	unsigned int	printf_length;

	i = 0;
	printf_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			printf_length += format(args, str[i + 1]);
			i++;
		}
		else
		{
			printf_length += ft_putchar(str[i]);
		}
		++i;
	}
	va_end(args);
	return (printf_length);
}
