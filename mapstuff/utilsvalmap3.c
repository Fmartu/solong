/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsvalmap3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:46:32 by fmartusc          #+#    #+#             */
/*   Updated: 2024/09/05 17:09:33 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

char	*ft_strdup1(const char *s1)
{
	char		*s2;
	size_t		i;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	itemscheck(t_game *g)
{
	g->e = 0;
	g->pl = 0;
	g->y = -1;
	g->ccount = 0;
	while (g->map[++g->y])
	{
		g->x = -1;
		while (g->map[g->y][++g->x])
		{
			if (!valid_char(g->map[g->y][g->x]))
				return (err(2));
			if (g->map[g->y][g->x] == 'P')
				g->pl++;
			if (g->map[g->y][g->x] == 'E')
				g->e++;
			if (g->map[g->y][g->x] == 'C')
				g->ccount++;
		}
	}
	if ((g->pl == 1) && (g->e == 1)
		&& (g->ccount >= 1))
		return (1);
	return (err(6));
}
