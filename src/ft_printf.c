/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:01:57 by manu              #+#    #+#             */
/*   Updated: 2022/05/08 20:40:00 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "utils.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		index;
	int		len;

	if (!format)
		return (0);
	va_start(args, format);
	len = 0;
	index = 0;
	while (format[index])
	{
		if (format[index] == '%')
			index++;
		else
			len += ft_putchar(format[index]);
		index++;
	}
	va_end(args);
	return (len);
}
