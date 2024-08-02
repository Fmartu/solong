/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:55:37 by fmartusc          #+#    #+#             */
/*   Updated: 2024/02/03 18:27:19 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_lin(long a)
{
	long	n;

	n = 1;
	if (a < 0)
		n *= -a;
	else
		n *= a;
	return (n);
}

static int	ft_nbrlen(long n)
{
	int	i;

	if (n < 0)
	{
		n = ft_lin(n);
		i = 1;
	}
	else
		i = 0;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	i;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	i = 1;
	while (n / i >= 10)
	{
		i = i * 10;
	}
	while (i > 0)
	{
		ft_putchar_fd((n / i + '0'), fd);
		n = n % i;
		i = i / 10;
	}
}

int	ft_putnbr(int n)
{
	int	nbr_len;

	nbr_len = ft_nbrlen(n);
	ft_putnbr_fd(n, 1);
	return (nbr_len);
}
