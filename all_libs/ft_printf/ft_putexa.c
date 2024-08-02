/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:30:07 by fmartusc          #+#    #+#             */
/*   Updated: 2024/02/03 18:30:28 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putexa(unsigned int nbr, char input)
{
	char			*base;
	unsigned long	num;
	int				i;
	unsigned int	base_len;

	if (input == 'x')
		base = "0123456789abcdef";
	if (input == 'X')
		base = "0123456789ABCDEF";
	i = 0;
	base_len = ft_strlen(base);
	num = nbr;
	if ((num + 1) > base_len)
		i += ft_putexa(num / base_len, input);
	i += ft_putchar(*(base + (num % base_len)));
	return (i);
}
