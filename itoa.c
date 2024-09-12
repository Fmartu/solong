/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:39:24 by fmartusc          #+#    #+#             */
/*   Updated: 2024/09/02 20:39:26 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	ft_nbrsz(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	ft_complstr(int size, int i, int n, char *str)
{
	while (size > i)
	{
		str[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	size = ft_nbrsz(n);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (0);
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
		i = 2;
	}
	if (n < 0)
	{
		str[0] = '-';
		i = 1;
		n = -n;
	}
	ft_complstr(size, i, n, str);
	str[size] = '\0';
	return (str);
}
