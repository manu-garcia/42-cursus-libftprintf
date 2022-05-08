/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:01:57 by manu              #+#    #+#             */
/*   Updated: 2022/05/08 21:15:04 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "utils.h"

#define SPECIFIER_AMPERSAND '%'
#define SPECIFIER_CHAR 'c'
#define SPECIFIER_STRING 's'

static int	process_specifier(char specifier, va_list args)
{
	int	len;

	len = 0;
	if (specifier == SPECIFIER_AMPERSAND)
		len += ft_putchar(specifier);
	else if (specifier == SPECIFIER_CHAR)
		len += ft_putchar(va_arg(args, int));
	else if (specifier == SPECIFIER_STRING)
		len += ft_putstring(va_arg(args, char *));
	return (len);
}

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
		if (format[index] == SPECIFIER_AMPERSAND)
		{
			len += process_specifier(format[index + 1], args);
			index++;
		}
		else
			len += ft_putchar(format[index]);
		index++;
	}
	va_end(args);
	return (len);
}
