/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:33:55 by fmartusc          #+#    #+#             */
/*   Updated: 2024/09/02 21:13:06 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	err(int ret)
{
	if (ret == 1)
		ft_printf(ERROR1);
	else if (ret == 2)
		ft_printf(ERROR2);
	else if (ret == 3)
		ft_printf(ERROR3);
	else if (ret == 4)
		ft_printf(ERROR4);
	else if (ret == 5)
		ft_printf(ERROR5);
	else if (ret == 6)
		ft_printf(ERROR6);
	else if (ret == 7)
		ft_printf(ERROR7);
	else if (ret == 8)
		ft_printf(ERROR8);
	return (0);
}

int	strlenline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	return (i);
}
