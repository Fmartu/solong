/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:08:00 by marvin            #+#    #+#             */
/*   Updated: 2024/02/03 18:25:00 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned long n)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789";
	if (n + 1 > (ft_strlen(base)))
		i += ft_putunsigned(n / ft_strlen(base));
	i += ft_putchar(*(base + (n % ft_strlen(base))));
	return (i);
}
