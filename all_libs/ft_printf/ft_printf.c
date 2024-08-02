/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:21:05 by fmartusc          #+#    #+#             */
/*   Updated: 2024/02/03 18:45:27 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_typeinput(va_list args, const char input)
{
	void	*ptr;

	if (input == 'c')
		return (ft_putchar((va_arg(args, int))));
	else if (input == 's')
		return (ft_putstr((va_arg(args, char *))));
	else if (input == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr == (void *)ULONG_MAX)
			return (ft_putstr("0xffffffffffffffff"));
		if (ptr)
			return (ft_putaddrss(ptr));
		return (ft_putstr("0x0"));
	}
	else if (input == 'i' || input == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (input == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (input == 'x' || input == 'X')
		return (ft_putexa(va_arg(args, unsigned int), input));
	else if (input == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	int		lenght;

	i = 0;
	lenght = 0;
	va_start(args, input);
	while (input[i])
	{
		if ((input[i]) == '%' && ft_strchr("cspdiuxX%", input[i + 1]))
		{
			lenght += ft_typeinput(args, input[i + 1]);
			i++;
		}
		else
			lenght += ft_putchar(input[i]);
		i++;
	}
	va_end(args);
	return (lenght);
}
