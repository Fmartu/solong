/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddrss.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:12:36 by fmartusc          #+#    #+#             */
/*   Updated: 2024/02/03 18:36:04 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	rec_print(unsigned long long n, const char *base)
{
	int	len;

	len = 0;
	if (n + 1 > (ft_strlen(base)))
		len += rec_print(n / ft_strlen(base), base);
	len += ft_putchar(*(base + (n % ft_strlen(base))));
	return (len);
}

int	ft_putaddrss(void *memaddrss)
{
	unsigned long long	n;
	const char			*base;
	long int			len;

	n = (unsigned long long)memaddrss;
	base = "0123456789abcdef";
	len = ft_putstr("0x");
	len += rec_print(n, base);
	return (len);
}
