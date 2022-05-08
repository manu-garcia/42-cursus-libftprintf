/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 20:21:45 by manu              #+#    #+#             */
/*   Updated: 2022/05/08 21:15:44 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstring(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len += ft_putchar(s[len]);
	return (len);
}
