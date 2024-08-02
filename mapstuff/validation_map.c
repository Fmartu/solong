/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:30:57 by fmartusc          #+#    #+#             */
/*   Updated: 2024/08/01 17:52:20 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int mapformat(char *argv)
{
    char *format;
    char *ber;

    format = argv;
    if (format)
    {
        ber = ft_strrchr(format, '.');
        if (ber)
        {
             ber++;
            {
                if (*ber == 'b')
                ber++;
                {
                    if (*ber == 'e')
                    ber++;
                    {
                        if (*ber == 'r')
                        ber++ ;
                        {
                            if (!(*ber))
                                return (1);
                        }
                    }
                }
            }
        }
        return (0); // mettici gnl con readfile.error  e zompa norminette
    }
}

int mapisrect(char)
